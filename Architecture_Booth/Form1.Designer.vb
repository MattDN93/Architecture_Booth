<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.MenuStrip1 = New System.Windows.Forms.MenuStrip()
        Me.AboutToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.TheoryToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.UnsignedBinaryMultiplicationToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.SignedRadix2BoothToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.HigherOrderMultiplicationToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.procChoiceList = New System.Windows.Forms.ComboBox()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.q_InputTextBox = New System.Windows.Forms.TextBox()
        Me.m_InputTextBox = New System.Windows.Forms.TextBox()
        Me.doMultButton = New System.Windows.Forms.Button()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.outputListBox = New System.Windows.Forms.RichTextBox()
        Me.GroupBox4 = New System.Windows.Forms.GroupBox()
        Me.MenuStrip1.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Segoe UI", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(94, 26)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(415, 20)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Computer Architecture: Number Muliplication Application"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(52, 52)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(503, 26)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Welcome to the application! To begin, choose an operation from the list, and ente" & _
    "r the necessary values. " & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "The operation is shown in the results window."
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'MenuStrip1
        '
        Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.AboutToolStripMenuItem, Me.TheoryToolStripMenuItem})
        Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip1.Name = "MenuStrip1"
        Me.MenuStrip1.Size = New System.Drawing.Size(588, 24)
        Me.MenuStrip1.TabIndex = 2
        Me.MenuStrip1.Text = "MenuStrip1"
        '
        'AboutToolStripMenuItem
        '
        Me.AboutToolStripMenuItem.Name = "AboutToolStripMenuItem"
        Me.AboutToolStripMenuItem.Size = New System.Drawing.Size(52, 20)
        Me.AboutToolStripMenuItem.Text = "About"
        '
        'TheoryToolStripMenuItem
        '
        Me.TheoryToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.UnsignedBinaryMultiplicationToolStripMenuItem, Me.SignedRadix2BoothToolStripMenuItem, Me.HigherOrderMultiplicationToolStripMenuItem})
        Me.TheoryToolStripMenuItem.Name = "TheoryToolStripMenuItem"
        Me.TheoryToolStripMenuItem.Size = New System.Drawing.Size(56, 20)
        Me.TheoryToolStripMenuItem.Text = "Theory"
        '
        'UnsignedBinaryMultiplicationToolStripMenuItem
        '
        Me.UnsignedBinaryMultiplicationToolStripMenuItem.Name = "UnsignedBinaryMultiplicationToolStripMenuItem"
        Me.UnsignedBinaryMultiplicationToolStripMenuItem.Size = New System.Drawing.Size(237, 22)
        Me.UnsignedBinaryMultiplicationToolStripMenuItem.Text = "Unsigned Binary Multiplication"
        '
        'SignedRadix2BoothToolStripMenuItem
        '
        Me.SignedRadix2BoothToolStripMenuItem.Name = "SignedRadix2BoothToolStripMenuItem"
        Me.SignedRadix2BoothToolStripMenuItem.Size = New System.Drawing.Size(237, 22)
        Me.SignedRadix2BoothToolStripMenuItem.Text = "Signed Radix 2 Booth Mult."
        '
        'HigherOrderMultiplicationToolStripMenuItem
        '
        Me.HigherOrderMultiplicationToolStripMenuItem.Name = "HigherOrderMultiplicationToolStripMenuItem"
        Me.HigherOrderMultiplicationToolStripMenuItem.Size = New System.Drawing.Size(237, 22)
        Me.HigherOrderMultiplicationToolStripMenuItem.Text = "Higher Order Multiplication"
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.procChoiceList)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 81)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(263, 64)
        Me.GroupBox1.TabIndex = 3
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Choose Process"
        '
        'procChoiceList
        '
        Me.procChoiceList.Cursor = System.Windows.Forms.Cursors.Arrow
        Me.procChoiceList.FormattingEnabled = True
        Me.procChoiceList.Items.AddRange(New Object() {"Choose a muliplication method...", "Unsigned number multiplication", "Signed number mult. with radix 2 Booth Algo", "Positive number mult. with radix 4 Booth Algo", "Positive number mult. with radix 8 Booth Algo"})
        Me.procChoiceList.Location = New System.Drawing.Point(12, 21)
        Me.procChoiceList.Name = "procChoiceList"
        Me.procChoiceList.Size = New System.Drawing.Size(239, 21)
        Me.procChoiceList.TabIndex = 0
        Me.procChoiceList.Text = "Choose a multiplication method..."
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.Label5)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Controls.Add(Me.q_InputTextBox)
        Me.GroupBox2.Controls.Add(Me.m_InputTextBox)
        Me.GroupBox2.Location = New System.Drawing.Point(292, 81)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(221, 64)
        Me.GroupBox2.TabIndex = 4
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Enter numbers:"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(136, 45)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(62, 13)
        Me.Label5.TabIndex = 5
        Me.Label5.Text = "Multiplier(Q)"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(104, 24)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(14, 13)
        Me.Label4.TabIndex = 3
        Me.Label4.Text = "X"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(14, 45)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(81, 13)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Multiplicand (M)"
        '
        'q_InputTextBox
        '
        Me.q_InputTextBox.Location = New System.Drawing.Point(122, 21)
        Me.q_InputTextBox.Name = "q_InputTextBox"
        Me.q_InputTextBox.Size = New System.Drawing.Size(89, 20)
        Me.q_InputTextBox.TabIndex = 1
        '
        'm_InputTextBox
        '
        Me.m_InputTextBox.Location = New System.Drawing.Point(11, 21)
        Me.m_InputTextBox.Name = "m_InputTextBox"
        Me.m_InputTextBox.Size = New System.Drawing.Size(87, 20)
        Me.m_InputTextBox.TabIndex = 0
        '
        'doMultButton
        '
        Me.doMultButton.Location = New System.Drawing.Point(7, 22)
        Me.doMultButton.Name = "doMultButton"
        Me.doMultButton.Size = New System.Drawing.Size(51, 23)
        Me.doMultButton.TabIndex = 2
        Me.doMultButton.Text = "Go!"
        Me.doMultButton.UseVisualStyleBackColor = True
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.doMultButton)
        Me.GroupBox3.Location = New System.Drawing.Point(518, 81)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(64, 64)
        Me.GroupBox3.TabIndex = 5
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Execute"
        '
        'outputListBox
        '
        Me.outputListBox.Location = New System.Drawing.Point(6, 19)
        Me.outputListBox.Name = "outputListBox"
        Me.outputListBox.Size = New System.Drawing.Size(558, 211)
        Me.outputListBox.TabIndex = 6
        Me.outputListBox.Text = ""
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.outputListBox)
        Me.GroupBox4.Location = New System.Drawing.Point(12, 151)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(570, 236)
        Me.GroupBox4.TabIndex = 7
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "Results"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(588, 399)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.MenuStrip1)
        Me.MainMenuStrip = Me.MenuStrip1
        Me.Name = "Form1"
        Me.Text = "Computer Architecture Project"
        Me.MenuStrip1.ResumeLayout(False)
        Me.MenuStrip1.PerformLayout()
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox4.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents MenuStrip1 As System.Windows.Forms.MenuStrip
    Friend WithEvents AboutToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents procChoiceList As System.Windows.Forms.ComboBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents TheoryToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents UnsignedBinaryMultiplicationToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents SignedRadix2BoothToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents HigherOrderMultiplicationToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents q_InputTextBox As System.Windows.Forms.TextBox
    Friend WithEvents m_InputTextBox As System.Windows.Forms.TextBox
    Friend WithEvents doMultButton As System.Windows.Forms.Button
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents outputListBox As System.Windows.Forms.RichTextBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox

End Class
