Public Class frmLeasing
    'Haleakela Lofts Leasing Assistant App - created by Tara Nguyen
    'Calculate final rent based on a base rent entered by user and on user's selection of building attributes

    Private Sub frmLeasing_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        cboBuilding.Text = "SunView"   'Assume SunView building upon form entry
    End Sub

    Private Sub btnCalculateRent_Click(sender As Object, e As EventArgs) Handles btnCalculateRent.Click
        'Calculate final rent only when user clicks on Calculate Rent button

        'Final rent if default attributes are not changed (i.e., building is SunView, with lanai inside)
        lblRent.Text = txtBaseRent.Text + 65

        'Final rent if default attributes are changed
        If cboBuilding.Text = "Crashing Surf" Then   'location
            lblRent.Text += 210
        End If
        If chkLanai.Checked = False Then   'no lanai
            lblRent.Text -= 65
        End If
        If chkRooftopDeck.Checked Then   'with rooftop deck
            lblRent.Text += 120
        End If
        If chkNonsmoking.Checked Then   'non-smoking
            lblRent.Text -= 25
        End If
    End Sub

    Private Sub btnExit_Click(sender As Object, e As EventArgs) Handles btnExit.Click
        Me.Close()   'End program when user clicks on Exit button
    End Sub
End Class
