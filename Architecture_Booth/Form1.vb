Public Class Form1


    '-------------Vars to show which process was selected--------------------'
    Friend unsignedMult As Boolean = False
    Friend rad2Booth As Boolean = False
    Friend rad4Booth As Boolean = False
    Friend rad8Booth As Boolean = False

    Friend procText As String = ""

    Private Sub AboutToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles AboutToolStripMenuItem.Click
        AboutBox1.Show()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles doMultButton.Click
        If q_InputTextBox.Text = "" Or m_InputTextBox.Text = "" Then
            MsgBox("You have not entered one of the values needed. Please try again.", MsgBoxStyle.Information, "Value Missing!")
            Exit Sub
        End If

        Try
            My.Computer.FileSystem.WriteAllText("valuesToMult.txt",
             m_InputTextBox.Text + " " + q_InputTextBox.Text, False)
        Catch ex As IO.IOException
            MsgBox("The fil could not be created/written to. Can't continue.", MsgBoxStyle.Critical, "An I/O Error Occurred!")
            Exit Sub
        End Try
        outputListBox.Items.Add("this is a test")
    End Sub

    Private Sub UnsignedBinaryMultiplicationToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles UnsignedBinaryMultiplicationToolStripMenuItem.Click
        unsignedMult = True
        TheoryPage.ShowDialog()
    End Sub

    Private Sub procChoiceList_SelectedIndexChanged(sender As Object, e As EventArgs) Handles procChoiceList.SelectedIndexChanged
        Select Case procChoiceList.SelectedItem
            Case "Unsigned number multiplication"
        End Select
       

    End Sub
End Class
