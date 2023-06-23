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
        //定义一个蛇
        private Snake mySnake;
        //定义一个食物
        private Food myFood;
        //定义蛇颜色
        private Color mySnakeColor;
        //定义食物颜色
        private Color myFoodColor;
        //定义一个颜色设置窗口
        颜色设置 gameColorSetting =new 颜色设置();
      
        public FormSnakeGame()
        {
            InitializeComponent();
            this.buttonStop.Enabled = false;
            ClearDirection();
            this.低水平ToolStripMenuItem.Checked = true;
            this.panelGame.BackgroundImage = Resources.myblog;
        }
 
        private void 游戏说明ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            游戏操作 gameOperationInformation = new 游戏操作();
            gameOperationInformation.Show();
        }
 
        private void 关于ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            关于 gameAbout = new 关于();
            gameAbout.Show();
        }
 
        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
 
        private void 颜色设置ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //gameColorSetting = new 颜色设置();
            gameColorSetting.Show();
        }
        
        //停止或暂停按键按下
        private static int i = 0;//用于判断显示Stop还是显示Continue
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
 
        //开始按键按下
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
            this.timerSnakeSpeed.Enabled = true;//启动计时器
        }
 
        //画蛇函数
        private void DrawSnake(Snake _newsnake)
        {
            foreach (Label lbl in _newsnake.GetSnake())
            {
                this.panelGame.Controls.Add(lbl);
            }
        }
 
        //定义一个Label存放当前食物
        Label currentfood = new Label();
        //发放食物
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
 
        //画食物函数
        private void DrawFood(Label newfood)
        {
            this.panelGame.Controls.Add(newfood);
        }
 
        //移除食物
        private void RemoveFood(Label oldfood)
        {
            this.panelGame.Controls.Remove(oldfood);
        }
 
        //计时器函数
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
 
        //清除水平选择标志
        private void ClearFlag()
        {
            this.低水平ToolStripMenuItem.Checked = false;
            this.普通水平ToolStripMenuItem.Checked = false;
            this.高水平ToolStripMenuItem.Checked = false;
        }
 
        //选择普通水平
        private void 普通水平ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFlag();
            this.普通水平ToolStripMenuItem.Checked = true ;
            this.timerSnakeSpeed.Interval = 300;
        }
 
        private void 高水平ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFlag();
            this.高水平ToolStripMenuItem.Checked = true;
            this.timerSnakeSpeed.Interval = 200;
        }
 
        private void 低水平ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearFlag();
            this.低水平ToolStripMenuItem.Checked = true;
            this.timerSnakeSpeed.Interval = 400;
        }
 
        //按键处理程序
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
        //W键按下
        private void buttonKeyW_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Down ? Direction.Down : Direction.Up);
            ClearColor();
            this.buttonKeyW.BackColor = Color.Blue;
        }
        //A键按下
        private void buttonKeyA_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Right ? Direction.Right : Direction.Left);
            ClearColor();
            this.buttonKeyA.BackColor = Color.Blue;
        }
        //S键按下
        private void buttonKeyS_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Up ? Direction.Up : Direction.Down);
            ClearColor();
            this.buttonKeyS.BackColor = Color.Blue;
        }
        //D键按下
        private void buttonKeyD_Click(object sender, EventArgs e)
        {
            this.mySnake.SnakeDirection = (this.mySnake.SnakeDirection == Direction.Left ? Direction.Left : Direction.Right);
            ClearColor();
            this.buttonKeyD.BackColor = Color.Blue;
        }
        //清除方向键背景颜色
        private void ClearColor()
        {
            this.buttonKeyW.BackColor = System.Windows.Forms.Button.DefaultBackColor;
            this.buttonKeyA.BackColor = System.Windows.Forms.Button.DefaultBackColor;
            this.buttonKeyS.BackColor = System.Windows.Forms.Button.DefaultBackColor;
            this.buttonKeyD.BackColor = System.Windows.Forms.Button.DefaultBackColor;
        }
        //方向键不可用
        private void ClearDirection()
        {
            this.buttonKeyA.Enabled = false;
            this.buttonKeyW.Enabled = false;
            this.buttonKeyD.Enabled = false;
            this.buttonKeyS.Enabled = false;
        }
        //方向键可用
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
作者：DreamMakers 
来源：CSDN 
原文：https://blog.csdn.net/majinggogogo/article/details/7491121 
版权声明：本文为博主原创文章，转载请附上博文链接！
