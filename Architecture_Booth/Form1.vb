Public Class Form1


    '-------------Vars to show which process was selected--------------------'
    Friend unsignedMult As Boolean = False
    Friend rad2Booth As Boolean = False
    Friend rad4Booth As Boolean = False
    Friend rad8Booth As Boolean = False

    Friend m_q_concat As String = ""
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
             m_InputTextBox.Text + vbCrLf + q_InputTextBox.Text, False)
        Catch ex As IO.IOException
            MsgBox("The file could not be created/written to. Can't continue.", MsgBoxStyle.Critical, "An I/O Error Occurred!")
            Exit Sub
        End Try

        m_q_concat = m_InputTextBox.Text + " " + q_InputTextBox.Text

        Dim ubmProcess As System.Diagnostics.Process
        Try         'launch each process based on choice made

            ubmProcess = New System.Diagnostics.Process()
            If unsignedMult = True Then
                ubmProcess.StartInfo.FileName = "unsignedBinaryMult.exe"
                ubmProcess.StartInfo.WindowStyle = ProcessWindowStyle.Minimized
            End If

            If rad2Booth = True Then
                ubmProcess.StartInfo.FileName = "radix2Booth.exe"
                ubmProcess.StartInfo.WindowStyle = ProcessWindowStyle.Minimized
            End If

            If rad4Booth = True Then
                ubmProcess.StartInfo.FileName = "radix4Booth.exe"
                ubmProcess.StartInfo.WindowStyle = ProcessWindowStyle.Minimized
            End If

            If rad8Booth = True Then
                ubmProcess.StartInfo.FileName = "radix8Booth.exe"
                ubmProcess.StartInfo.WindowStyle = ProcessWindowStyle.Minimized
            End If

            ubmProcess.StartInfo.Arguments = m_q_concat
            ubmProcess.Start()

            'Wait until the process passes back an exit code 
            ubmProcess.WaitForExit()
            'Free resources associated with this process
            ubmProcess.Close()
            'Catch
            'Try
            '    Process.Start(Application.StartupPath & "\\unsignedBinaryMult.exe", m_q_concat)
        Catch ex As System.ComponentModel.Win32Exception
            MsgBox("Process could not be started. Execution halted!", MsgBoxStyle.Critical, "Couldn't Open Process!")
            Exit Sub
        End Try

        Try
            procText = My.Computer.FileSystem.ReadAllText("valuesToDisplay.txt")
        Catch ex As IO.FileNotFoundException
            MsgBox("The file could not be read from. Can't continue.", MsgBoxStyle.Critical, "An I/O Error Occurred!")
            Exit Sub
        End Try
        outputListBox.Items.Add(procText)
        outputListBox.Items.Add("this is a test")

        unsignedMult = False
        rad2Booth = False
        rad4Booth = False
        rad8Booth = False

    End Sub

    Private Sub UnsignedBinaryMultiplicationToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles UnsignedBinaryMultiplicationToolStripMenuItem.Click
        unsignedMult = True
        TheoryPage.ShowDialog()
    End Sub

    Private Sub procChoiceList_SelectedIndexChanged(sender As Object, e As EventArgs) Handles procChoiceList.SelectedIndexChanged
        Select Case procChoiceList.Text
            Case "Unsigned number multiplication" : unsignedMult = True
                rad2Booth = False
                rad4Booth = False
                rad8Booth = False
                MsgBox("doing USIGN")

                q_InputTextBox.Clear()
                m_InputTextBox.Clear()

                doMultButton.Enabled = False
                q_InputTextBox.Enabled = True
                m_InputTextBox.Enabled = True
            Case "Signed number mult. with radix 2 Booth Algo" : rad2Booth = True
                unsignedMult = False
                rad4Booth = False
                rad8Booth = False
                MsgBox("doing radix2")

                q_InputTextBox.Clear()
                m_InputTextBox.Clear()

                doMultButton.Enabled = False
                q_InputTextBox.Enabled = True
                m_InputTextBox.Enabled = True
            Case "Positive number mult. with radix 4 Booth Algo" : rad4Booth = True
                unsignedMult = True
                rad2Booth = False
                rad8Booth = False
                MsgBox("doing radix4")

                q_InputTextBox.Clear()
                m_InputTextBox.Clear()

                doMultButton.Enabled = False
                q_InputTextBox.Enabled = True
                m_InputTextBox.Enabled = True
            Case "Positive number mult. with radix 8 Booth Algo" : rad8Booth = True
                unsignedMult = False
                rad2Booth = False
                rad4Booth = False

                MsgBox("doing radix8")
                q_InputTextBox.Clear()
                m_InputTextBox.Clear()

                doMultButton.Enabled = False
                q_InputTextBox.Enabled = True
                m_InputTextBox.Enabled = True
            Case Else : MsgBox("No process choice was made. Please choose an option!", MsgBoxStyle.Information, "No choice made")
                q_InputTextBox.Clear()
                m_InputTextBox.Clear()
                doMultButton.Enabled = False
                q_InputTextBox.Enabled = False
                m_InputTextBox.Enabled = False
        End Select
       

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        doMultButton.Enabled = False
        q_InputTextBox.Enabled = False
        m_InputTextBox.Enabled = False
    End Sub

    Private Sub m_InputTextBox_TextChanged(sender As Object, e As EventArgs) Handles m_InputTextBox.TextChanged
        doMultButton.Enabled = True
    End Sub

    Private Sub q_InputTextBox_TextChanged(sender As Object, e As EventArgs) Handles q_InputTextBox.TextChanged
        doMultButton.Enabled = True
    End Sub
End Class
