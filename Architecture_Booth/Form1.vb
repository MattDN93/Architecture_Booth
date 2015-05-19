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
        = "Unsigned number multiplication" Then
        unsignedMult = True
        End If
    End Sub
End Class
