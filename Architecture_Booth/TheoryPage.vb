Imports System.Windows.Forms

Public Class TheoryPage

    Private Sub OK_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OK_Button.Click
        Me.DialogResult = System.Windows.Forms.DialogResult.OK
        Me.Close()
    End Sub

    Private Sub Cancel_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.Close()
    End Sub

    Private Sub TheoryPage_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If Form1.unsignedMult = True Then
            PictureBox1.Show()
            PictureBox1.Image = CType(My.Resources.ResourceManager.GetObject(String.Format("unsignedBin.png")), Image)
        ElseIf Form1.rad2Booth = True Then
            PictureBox1.Image = CType(My.Resources.ResourceManager.GetObject(String.Format("rad2Booth")), Image)
        ElseIf Form1.rad4Booth = True Then
            PictureBox1.Image = CType(My.Resources.ResourceManager.GetObject(String.Format("unsignedBin")), Image)
        ElseIf Form1.rad8Booth = True Then
            PictureBox1.Image = CType(My.Resources.ResourceManager.GetObject(String.Format("unsignedBin")), Image)
        Else
            PictureBox1.Hide()
        End If
    End Sub
End Class
