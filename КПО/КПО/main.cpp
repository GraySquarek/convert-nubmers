using System;

using System.Windows.Forms;

namespace Lab3

{

public enum Marks { none = 0, veryBad = 1, bad = 2, satis = 3, good = 4, excelent = 5, NoSetOff = 7, SetOff = 6 }

public enum MarkButtons { _2marks = 0, _5marks = 1 }

class MyDialog

{

static Form vf;

public static Marks Show(string msg, string caption, MarkButtons btns)

{

vf = new Form();

vf.Text = caption;

Label vl = new Label();

vl.Left = 50;

vl.Top = 20;

vl.Text = msg;

vf.Controls.Add(vl);

Button vb;

switch (btns)

{

case MarkButtons._2marks:

vb = new Button();

vb.Text = "Неявка";

vb.Top = 50;

vb.DialogResult = (DialogResult)(Marks.NoSetOff);

vb.Left = 40;

vf.Controls.Add(vb);

vb.Click += Button_Click;

vb = new Button();

vb.Text = "1";

vb.Top = 50;

vb.DialogResult = (DialogResult)(Marks.NoSetOff);

vb.Left = 130;

vf.Controls.Add(vb);

vb.Click += Button_Click;

vb = new Button();

vb.Text = "2";

vb.Top = 50;

vb.DialogResult = (DialogResult)(Marks.NoSetOff);

vb.Left = 220;

vf.Controls.Add(vb);

vb = new Button();

vb.Click += Button_Click;

vb.Text = "3";

vb.Top = 50;

vb.DialogResult = (DialogResult)(Marks.SetOff);

vb.Left = 310;

vf.Controls.Add(vb);

vb.Click += Button_Click;

vb = new Button();

vb.Click += Button_Click;

vb.Text = "4";

vb.Top = 50;

vb.DialogResult = (DialogResult)(Marks.SetOff);

vb.Left = 400;

vf.Controls.Add(vb);

vb.Click += Button_Click;

vb = new Button();

vb.Click += Button_Click;

vb.Text = "5";

vb.Top = 50;

vb.DialogResult = (DialogResult)(Marks.SetOff);

vb.Left = 490;

vf.Controls.Add(vb);

vb.Click += Button_Click;

if (vf.ShowDialog() == DialogResult.No) return Marks.NoSetOff;

else return Marks.SetOff;

case MarkButtons._5marks:

break;

};

return Marks.none;

}

    private static void :Button_Click(object sender, EventArgs e)

{

vf.DialogResult = (sender as Button).DialogResult;

}

}

}
