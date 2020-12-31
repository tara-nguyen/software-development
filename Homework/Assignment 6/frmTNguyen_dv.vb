Public Class frmDesertVistas
    'Lease pricing app for the Desert Vista Country Club
    'Created by Tara Nguyen

    'Declare variables

    Dim rent As Double      'montly rent
    Dim deposit As Double   'deposit amount

    'Define constants

    Const MINBASERENT = 1000     'minimum possible base rent
    Const TWOBEDROOMPREM = 150   'added price for 2-bedroom units
    Const CASITAPREM = 96        'added price for Casita units
    Const HALFBATHSPREM = 60     'added price for 1 1/2 Baths in 1-bedroom units
    Const TWOBATHSPREM = 37      'added price for 2 Full Baths in 2-bedroom units
    Const GREENBELTPREM = 1.06   'pricing multiplier for Green Belt view
    Const SJMPREM = 1.15         'pricing multiplier for San Jacinto Mountains view
    Const BESTVIEWPREM = 1.33    'pricing multiplier for Golf Course, Lakes, or Santa Rosa Mountains views
    Const NOLANAIDISCNT = -42    'discount for units with no lanai
    Const PETCHARGE = 25         'added charge for having a pet
    Const GOLFCHARGE = 70        'added charge for having golf cart space
    Const POOLCHARGE = 10        'added charge for pool proximity
    Const PETDEPOSIT = 200       'extra deposit for having a pet
    Const GOLFDEPOSIT = 50       'extra deposit for having golf cart space

    Private Sub SetTahquitzOptions()
        'Set options for Tahquitz area

        rdo1Bedroom.Enabled = True    '1-bedroom units available
        rdo1Bedroom.Checked = True    '1-bedroom unit selected
        rdo2Bedrooms.Enabled = True   '2-bedroom units available
        rdoCasita.Enabled = False     'Casita units not available
        rdoLoft.Enabled = False       'Loft units not available
    End Sub

    Private Sub SetPalmIslandOptions()
        'Set options for Palm Island area

        rdo1Bedroom.Enabled = True    '1-bedroom units available
        rdo2Bedrooms.Enabled = True   '2-bedroom units available
        rdoCasita.Enabled = True      'Casita units available
        rdoLoft.Enabled = False       'Loft units not available
    End Sub

    Private Sub SetModerneOptions()
        'Set options for Moderne area

        rdo1Bedroom.Enabled = False    '1-bedroom unit not available
        rdo2Bedrooms.Enabled = False   '2-bedroom units not available
        rdoCasita.Enabled = False      'Casita units not available
        rdoLoft.Enabled = True         'Loft units available
        rdoLoft.Checked = True         'Lot unit selected

        cboView.Text = "San Jacinto Mountains"   'default view
    End Sub

    Private Sub DisplayViewError()
        'Control what happens when user selects views that are not available to Moderne area
        If rdoModerne.Checked Then
            If cboView.Text = "Golf Course" Or cboView.Text = "Lakes" Then
                'Display error message
                MessageBox.Show(cboView.Text & " View not available from Moderne", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)

                'Select San Jacinto Mountains view
                cboView.Text = "San Jacinto Mountains"
            End If
        End If
    End Sub

    Private Sub Set1BedroomOptions()
        'Set options for 1-bedroom units

        rdo1FullBath.Enabled = True       '1 Full Bath available
        rdo1FullBath.Checked = True       '1 Full Bath selected
        rdo1andHalfBaths.Enabled = True   '1 1/2 Baths available
        rdo2FullBaths.Enabled = False     '2 Full Baths available
    End Sub

    Private Sub Set2BedroomsOptions()
        'Set options for 2-bedroom units

        rdo1FullBath.Enabled = False      '1 Full Bath available
        rdo1andHalfBaths.Enabled = True   '1 1/2 Baths available
        rdo1andHalfBaths.Checked = True   '1 1/2 Baths selected
        rdo2FullBaths.Enabled = True      '2 Full Baths available
    End Sub

    Private Sub SetOtherBedroomOptions()
        'Set options for Casita and Loft units

        rdo1FullBath.Enabled = True        '1 Full Bath available
        rdo1FullBath.Checked = True        '1 Full Bath selected
        rdo1andHalfBaths.Enabled = False   '1 1/2 Baths available
        rdo2FullBaths.Enabled = False      '2 Full Baths available
    End Sub

    Private Sub CalcUnitRent()
        'Calculate rent based on options of bedrooms and bathrooms

        If rdo1Bedroom.Checked Then   '1-bedroom
            If rdo1andHalfBaths.Checked Then   '1 1/2 Baths
                rent += HALFBATHSPREM
            End If
        ElseIf rdo2Bedrooms.Checked Then   '2-bedroom
            rent += TWOBEDROOMPREM
            If rdo2FullBaths.Checked Then   '2 Full Baths
                rent += TWOBATHSPREM
            End If
        ElseIf rdoCasita.Checked Then   'Casita unit
            rent += CASITAPREM
        ElseIf rdoLoft.Checked Then   'Loft unit
            rent += txtBaseRent.Text
        End If
    End Sub

    Private Sub CalcViewRent()
        'Calculate rent based on options of views

        If cboView.Text = "Greenbelt" Then
            rent *= GREENBELTPREM
        ElseIf cboView.Text = "San Jacinto Mountains" Then
            rent *= SJMPREM
        ElseIf cboView.Text = "Golf Course" Or cboView.Text = "Lakes" Or cboView.Text = "Santa Rosa Mountains" Then
            rent *= BESTVIEWPREM
        End If
    End Sub

    Private Sub CalcAmenitiesRent()
        'Calculate rent and deposit based on options of amenities and tenant specifics

        If chkLanai.Checked = False Then   'no lanai
            rent += NOLANAIDISCNT
        End If
        If chkPet.Checked Then   'having pet
            rent += PETCHARGE
        End If
        If chkGolf.Checked Then   'having golf cart space
            rent += GOLFCHARGE
        End If
        If chkPool.Checked Then   'pool proximity
            rent += POOLCHARGE
        End If
    End Sub

    Private Sub CalcDeposit()
        'Calculate deposit

        deposit = rent

        If chkPet.Checked Then   'having pet
            deposit += PETDEPOSIT
        End If
        If chkGolf.Checked Then   'having goal cart space
            deposit += GOLFDEPOSIT
        End If
        If chkBadCredit.Checked Then   'renters with bad credit
            deposit = Math.Round(rent) * 2
        End If
    End Sub

    Private Sub frmDesertVistas_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Set defaults upon entering the form

        txtBaseRent.Text = MINBASERENT   'minimum base rent displayed
        rent = txtBaseRent.Text          'monthly rent
        rdoTahquitz.Checked = True       'Tahquitz area selected (and thus options not available to Tahquitz disabled)
        rdo1Bedroom.Checked = True       '1-bedroom unit selected (and thus options not available to 1-bedroom unit disabled)
        cboView.Text = "Parking"         'Parking view selected
        chkLanai.Checked = True          'lanai selected
    End Sub

    Private Sub rdoTahquitz_CheckedChanged(sender As Object, e As EventArgs) Handles rdoTahquitz.CheckedChanged
        If rdoTahquitz.Checked Then
            SetTahquitzOptions()
        End If
    End Sub

    Private Sub rdoPalmIsland_CheckedChanged(sender As Object, e As EventArgs) Handles rdoPalmIsland.CheckedChanged
        If rdoPalmIsland.Checked Then
            SetPalmIslandOptions()
        End If
    End Sub

    Private Sub rdoModerne_CheckedChanged(sender As Object, e As EventArgs) Handles rdoModerne.CheckedChanged
        If rdoModerne.Checked Then
            SetModerneOptions()
        End If
    End Sub

    Private Sub rdo1Bedroom_CheckedChanged(sender As Object, e As EventArgs) Handles rdo1Bedroom.CheckedChanged
        'Control what happens when 1-bedroom unit is selected
        If rdo1Bedroom.Checked Then
            Set1BedroomOptions()
        End If
    End Sub

    Private Sub rdo2Bedrooms_CheckedChanged(sender As Object, e As EventArgs) Handles rdo2Bedrooms.CheckedChanged
        'Control what happens when 2-bedroom unit is selected
        If rdo2Bedrooms.Checked Then
            Set2BedroomsOptions()
        End If
    End Sub

    Private Sub rdoCasita_CheckedChanged(sender As Object, e As EventArgs) Handles rdoCasita.CheckedChanged
        'Control what happens when Casita unit is selected
        If rdoCasita.Checked Then
            SetOtherBedroomOptions()
        End If
    End Sub

    Private Sub rdoLoft_CheckedChanged(sender As Object, e As EventArgs) Handles rdoLoft.CheckedChanged
        'Control what happens when Loft unit is selected
        If rdoLoft.Checked Then
            SetOtherBedroomOptions()
        End If
    End Sub

    Private Sub cboView_SelectedIndexChanged(sender As Object, e As EventArgs) Handles cboView.SelectedIndexChanged
        DisplayViewError()
    End Sub

    Private Sub btnExit_Click(sender As Object, e As EventArgs) Handles btnExit.Click
        Me.Close()   'Exit form
    End Sub

    Private Sub CozyLovenestToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles CozyLovenestToolStripMenuItem.Click
        'Set options when Cozy Lovenest is selected

        rdoPalmIsland.Checked = True   'Palm Island area
        rdoCasita.Checked = True       'Casita unit
        cboView.Text = "Lakes"         'Lakes view
        chkLanai.Checked = False       'no lanai in unit
        chkPool.Checked = False        'no pool proximity
        chkGolf.Checked = False        'no golf cart space
        chkPet.Checked = False         'no pet
        chkBadCredit.Checked = False   'no bad credit
    End Sub

    Private Sub ExecutiveCoolPadToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExecutiveCoolPadToolStripMenuItem.Click
        'Set options when Executive Cool Pad is selected

        rdoModerne.Checked = True      'Moderne area
        chkLanai.Checked = True        'lanai in unit
        chkPool.Checked = False        'no pool proximity
        chkGolf.Checked = True         'golf cart space
        chkPet.Checked = True          'with pet
        chkBadCredit.Checked = False   'no bad credit
    End Sub

    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        Me.Close()   'Exit form
    End Sub

    Private Sub btnCalculate_Click(sender As Object, e As EventArgs) Handles btnCalculate.Click
        'Calculate and display rent and deposit when user clicks on Calculate button

        'Check that the base rent entered is a number that's at least the minimum base rent
        If Not IsNumeric(txtBaseRent.Text) Then
            lblRent.Text = "Error"
            lblDeposit.Text = "Error"
            MessageBox.Show("Base rent must be a number", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            txtBaseRent.Clear()
            txtBaseRent.Focus()
        ElseIf txtBaseRent.Text < MINBASERENT Then
            lblRent.Text = "Error"
            lblDeposit.Text = "Error"
            MessageBox.Show("Base rent must be 1000 or higher", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            txtBaseRent.Clear()
            txtBaseRent.Focus()
        Else
            rent = txtBaseRent.Text

            'Calculate rent for different options

            CalcUnitRent()        'based on bedroom and bathroom options
            CalcViewRent()        'based on view options
            CalcAmenitiesRent()   'based on amenities and tenant specifics

            'Calculate deposit

            CalcDeposit()

            'Display rent and deposit

            lblRent.Text = FormatCurrency(Math.Round(rent), 0)
            lblDeposit.Text = FormatCurrency(Math.Round(deposit), 0)
        End If
    End Sub
End Class
