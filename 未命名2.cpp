using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using SnakeGame.Properties;
 
namespace SnakeGame
{
    public partial class FormSnakeGame : Form
    {
        //����һ����
        private Snake mySnake;
        //����һ��ʳ��
        private Food myFood;
        //��������ɫ
        private Color mySnakeColor;
        //����ʳ����ɫ
        private Color myFoodColor;
        //����һ����ɫ���ô���
        ��ɫ���� gameColorSetting =new ��ɫ����();
      
        public FormSnakeGame()
        {
            InitializeComponent();
            this.buttonStop.Enabled = false;
            ClearDirection();
            this.��ˮƽToolStripMenuItem.Checked = true;
            this.panelGame.BackgroundImage = Resources.myblog;
        }
 
        private void ��Ϸ˵��ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            ��Ϸ���� gameOperationInformation = new ��Ϸ����();
            gameOperationInformation.Show();
        }
 
        private void ����ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ���� gameAbout = new ����();
            gameAbout.Show();
        }
 
        private void �˳�ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
 
        private void ��ɫ����ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //gameColorSetting = new ��ɫ����();
            gameColorSetting.Show();
        }
        
        //ֹͣ����ͣ��������
        private static int i = 0;//�����ж���ʾStop������ʾContinue
        private void buttonStop_Click(object sender, EventArgs e)
        {
            if (i++ % 2 == 0)
            {
                this.buttonStop.Text = "Continue";
                this.timerSnakeSpeed.Enabled = false;
            }
            else
            {
                this.buttonStop.Text = "Stop";
                this.timerSnakeSpeed.Enabled = true;
            }
        }
 
        //��ʼ��������
        private void buttonStart_Click(object sender, EventArgs e)
        {
            this.panelGame.BackgroundImage = null;
            this.buttonStart.Enabled = false;
            EnableDirection();
            mySnakeColor = gameColorSetting.SetSnakeColor;
            myFoodColor = gameColorSetting.SetFoodColor;
            this.buttonStop.Enabled = true;
            mySnake = new Snake(mySnakeColor);
            foreach (Label lbl in mySnake.GetSnake())
            {
                this.panelGame.Controls.Add(lbl);
            }
            myFood = new Food(myFoodColor,new Point(100,100));
            this.panelGame.Controls.Add(myFood.FoodCeil);
            this.myFood.CopyFoodCeil(currentfood, this.myFood.FoodCeil);
            this.timerSnakeSpeed.Enabled = true;//������ʱ��
        }
 
        //���ߺ���
        private void DrawSnake(Snake _newsnake)
        {
            foreach (Label lbl in _newsnake.GetSnake())
            {
                this.panelGame.Controls.Add(lbl);
            }
        }
 
        //����һ��Label��ŵ�ǰʳ��
        Label currentfood = new Label();
        //����ʳ��
        private void PutFood()
        {
            Random randfood = new Random();
            int newfoodx = randfood.Next(35);
            int newfoody = randfood.Next(28);
            Label newfood = new Label();
            this.myFood.CopyFoodCeil(newfood, currentfood);
            newfood.Left = newfoodx*10;
            newfood.Top = newfoody*10;
            this.panelGame.Controls.Remove(this.myFood.FoodCeil);
            this.panelGame.Controls.Add(newfood);
            this.myFood.CopyFoodCeil(this.myFood.FoodCeil, newfood);
            this.myFood.CopyFoodCeil(currentfood, newfood);
        }
 
        //��ʳ�ﺯ��
        private void DrawFood(Label newfood)
        {
            this.panelGame.Controls.Add(newfood);
        }
 
        //�Ƴ�ʳ��
        private void RemoveFood(Label oldfood)
        {
            this.panelGame.Controls.Remove(oldfood);
        }
 
        //��ʱ������
        private void timerSnakeSpeed_Tick(object sender, EventArgs e)
        {
            mySnake.EatFood(this.myFood.FoodCeil);
            mySnake.Move(this.panelGame,this.myFood.FoodCeil);
            DrawSnake(mySnake);
            if (this.mySnake.IsDead)
            {
                this.buttonStart.Enabled = true;
                this.buttonStop.Enabled = false;
                this.timerSnakeSpeed.Enabled = false;
                ClearColor();
                ClearDirection();
                this.textBoxScore.Text = "";
                this.panelGame.Controls.Clear();
                this.panelGame.BackgroundImage = Resources.gameover1;
            }
            if (mySnake.Flag)
            {
                PutFood();
                mySnake.Flag = false;
            }
            this.textBoxScore.Text = ((mySnake.SnakeLength - 5) * 10).ToString();
        }
 
        //���ˮƽѡ���־
        private void ClearFlag()
        {
            this.��ˮƽToolStripMenuItem.Checked = false;
            this.��ͨˮƽToolStripMenuItem.Checked = false;
            this.��ˮƽToolStripMenuItem.Checked = false;
        }
 
        //ѡ����ͨˮƽ
        private void ��ͨˮƽToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFlag();
            this.��ͨˮƽToolStripMenuItem.Checked = true ;
            this.timerSnakeSpeed.Interval = 300;
        }
 
        private void ��ˮƽToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFlag();
            this.��ˮƽToolStripMenuItem.Checked = true;
            this.timerSnakeSpeed.Interval = 200;
        }
 
        private void ��ˮƽToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFlag();
            this.��ˮƽToolStripMenuItem.Checked = true;
            this.timerSnakeSpeed.Interval = 400;
        }
 
        //�����������
        private void FormSnakeGame_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 'a' || e.KeyChar == 'A')
            { 
                this.mySnake.SnakeDirection=(this.mySnake.SnakeDirection==Direction.Right?Direction.Right:Direction.Left);
                ClearColor();
                this.buttonKeyA.BackColor = Color.Blue;
            }
            else if (e.KeyChar == 'd' || e.KeyChar == 'D')
            {
                this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Left ? Direction.Left : Direction.Right);
                ClearColor();
                this.buttonKeyD.BackColor = Color.Blue;
            }
            else if (e.KeyChar == 'w' || e.KeyChar == 'W')
            {
                this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Down ? Direction.Down : Direction.Up);
                ClearColor();
                this.buttonKeyW.BackColor = Color.Blue;
            }
            else if (e.KeyChar == 's' || e.KeyChar == 'S')
            {
                this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Up ? Direction.Up : Direction.Down);
                ClearColor();
                this.buttonKeyS.BackColor = Color.Blue;
            }
            else
            {
                e.Handled = true;
            }
        }
        //W������
        private void buttonKeyW_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Down ? Direction.Down : Direction.Up);
            ClearColor();
            this.buttonKeyW.BackColor = Color.Blue;
        }
        //A������
        private void buttonKeyA_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Right ? Direction.Right : Direction.Left);
            ClearColor();
            this.buttonKeyA.BackColor = Color.Blue;
        }
        //S������
        private void buttonKeyS_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Up ? Direction.Up : Direction.Down);
            ClearColor();
            this.buttonKeyS.BackColor = Color.Blue;
        }
        //D������
        private void buttonKeyD_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Left ? Direction.Left : Direction.Right);
            ClearColor();
            this.buttonKeyD.BackColor = Color.Blue;
        }
        //��������������ɫ
        private void ClearColor()
        {
            this.buttonKeyW.BackColor = System.Windows.Forms.Button.DefaultBackColor;
            this.buttonKeyA.BackColor = System.Windows.Forms.Button.DefaultBackColor;
            this.buttonKeyS.BackColor = System.Windows.Forms.Button.DefaultBackColor;
            this.buttonKeyD.BackColor = System.Windows.Forms.Button.DefaultBackColor;
        }
        //�����������
        private void ClearDirection()
        {
            this.buttonKeyA.Enabled = false;
            this.buttonKeyW.Enabled = false;
            this.buttonKeyD.Enabled = false;
            this.buttonKeyS.Enabled = false;
        }
        //���������
        private void EnableDirection()
        {
            this.buttonKeyA.Enabled = true;
            this.buttonKeyW.Enabled = true;
            this.buttonKeyD.Enabled = true;
            this.buttonKeyS.Enabled = true;
        }
    }
}
--------------------- 
���ߣ�DreamMakers 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/majinggogogo/article/details/7491121 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
