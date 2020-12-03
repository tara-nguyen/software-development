<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmLeasing
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
        Me.lblTitle = New System.Windows.Forms.Label()
        Me.txtBaseRent = New System.Windows.Forms.TextBox()
        Me.lblBaseRent = New System.Windows.Forms.Label()
        Me.lblSlogan = New System.Windows.Forms.Label()
        Me.lblBuilding = New System.Windows.Forms.Label()
        Me.cboBuilding = New System.Windows.Forms.ComboBox()
        Me.chkLanai = New System.Windows.Forms.CheckBox()
        Me.chkRooftopDeck = New System.Windows.Forms.CheckBox()
        Me.chkNonsmoking = New System.Windows.Forms.CheckBox()
        Me.lblRentTitle = New System.Windows.Forms.Label()
        Me.lblRent = New System.Windows.Forms.Label()
        Me.btnCalculateRent = New System.Windows.Forms.Button()
        Me.btnExit = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lblTitle
        '
        Me.lblTitle.AutoSize = True
        Me.lblTitle.Font = New System.Drawing.Font("Microsoft Sans Serif", 20.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblTitle.Location = New System.Drawing.Point(38, 32)
        Me.lblTitle.Name = "lblTitle"
        Me.lblTitle.Size = New System.Drawing.Size(217, 31)
        Me.lblTitle.TabIndex = 0
        Me.lblTitle.Text = "Haleakela Lofts"
        '
        'txtBaseRent
        '
        Me.txtBaseRent.Location = New System.Drawing.Point(104, 113)
        Me.txtBaseRent.Name = "txtBaseRent"
        Me.txtBaseRent.Size = New System.Drawing.Size(88, 20)
        Me.txtBaseRent.TabIndex = 1
        '
        'lblBaseRent
        '
        Me.lblBaseRent.AutoSize = True
        Me.lblBaseRent.Location = New System.Drawing.Point(41, 116)
        Me.lblBaseRent.Name = "lblBaseRent"
        Me.lblBaseRent.Size = New System.Drawing.Size(57, 13)
        Me.lblBaseRent.TabIndex = 2
        Me.lblBaseRent.Text = "Base Rent"
        '
        'lblSlogan
        '
        Me.lblSlogan.AutoSize = True
        Me.lblSlogan.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblSlogan.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblSlogan.Location = New System.Drawing.Point(322, 42)
        Me.lblSlogan.Name = "lblSlogan"
        Me.lblSlogan.Size = New System.Drawing.Size(264, 22)
        Me.lblSlogan.TabIndex = 3
        Me.lblSlogan.Text = "Where Crashing Surf Meets the Sky"
        '
        'lblBuilding
        '
        Me.lblBuilding.AutoSize = True
        Me.lblBuilding.Location = New System.Drawing.Point(41, 158)
        Me.lblBuilding.Name = "lblBuilding"
        Me.lblBuilding.Size = New System.Drawing.Size(44, 13)
        Me.lblBuilding.TabIndex = 4
        Me.lblBuilding.Text = "Building"
        '
        'cboBuilding
        '
        Me.cboBuilding.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cboBuilding.FormattingEnabled = True
        Me.cboBuilding.Items.AddRange(New Object() {"Crashing Surf", "SunView"})
        Me.cboBuilding.Location = New System.Drawing.Point(104, 155)
        Me.cboBuilding.Name = "cboBuilding"
        Me.cboBuilding.Size = New System.Drawing.Size(121, 21)
        Me.cboBuilding.TabIndex = 5
        '
        'chkLanai
        '
        Me.chkLanai.AutoSize = True
        Me.chkLanai.Checked = True
        Me.chkLanai.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkLanai.Location = New System.Drawing.Point(404, 115)
        Me.chkLanai.Name = "chkLanai"
        Me.chkLanai.Size = New System.Drawing.Size(52, 17)
        Me.chkLanai.TabIndex = 6
        Me.chkLanai.Text = "Lanai"
        Me.chkLanai.UseVisualStyleBackColor = True
        '
        'chkRooftopDeck
        '
        Me.chkRooftopDeck.AutoSize = True
        Me.chkRooftopDeck.Location = New System.Drawing.Point(404, 158)
        Me.chkRooftopDeck.Name = "chkRooftopDeck"
        Me.chkRooftopDeck.Size = New System.Drawing.Size(93, 17)
        Me.chkRooftopDeck.TabIndex = 7
        Me.chkRooftopDeck.Text = "Rooftop Deck"
        Me.chkRooftopDeck.UseVisualStyleBackColor = True
        '
        'chkNonsmoking
        '
        Me.chkNonsmoking.AutoSize = True
        Me.chkNonsmoking.Location = New System.Drawing.Point(404, 201)
        Me.chkNonsmoking.Name = "chkNonsmoking"
        Me.chkNonsmoking.Size = New System.Drawing.Size(88, 17)
        Me.chkNonsmoking.TabIndex = 8
        Me.chkNonsmoking.Text = "Non-smoking"
        Me.chkNonsmoking.UseVisualStyleBackColor = True
        '
        'lblRentTitle
        '
        Me.lblRentTitle.AutoSize = True
        Me.lblRentTitle.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblRentTitle.Location = New System.Drawing.Point(40, 233)
        Me.lblRentTitle.Name = "lblRentTitle"
        Me.lblRentTitle.Size = New System.Drawing.Size(53, 24)
        Me.lblRentTitle.TabIndex = 9
        Me.lblRentTitle.Text = "Rent"
        '
        'lblRent
        '
        Me.lblRent.BackColor = System.Drawing.Color.Aqua
        Me.lblRent.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblRent.Font = New System.Drawing.Font("Microsoft Sans Serif", 18.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblRent.Location = New System.Drawing.Point(44, 257)
        Me.lblRent.Name = "lblRent"
        Me.lblRent.Size = New System.Drawing.Size(181, 60)
        Me.lblRent.TabIndex = 10
        Me.lblRent.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'btnCalculateRent
        '
        Me.btnCalculateRent.Location = New System.Drawing.Point(353, 269)
        Me.btnCalculateRent.Name = "btnCalculateRent"
        Me.btnCalculateRent.Size = New System.Drawing.Size(100, 45)
        Me.btnCalculateRent.TabIndex = 11
        Me.btnCalculateRent.Text = "Calculate Rent"
        Me.btnCalculateRent.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.Location = New System.Drawing.Point(459, 269)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(100, 45)
        Me.btnExit.TabIndex = 12
        Me.btnExit.Text = "Exit"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'frmLeasing
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(634, 365)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnCalculateRent)
        Me.Controls.Add(Me.lblRent)
        Me.Controls.Add(Me.lblRentTitle)
        Me.Controls.Add(Me.chkNonsmoking)
        Me.Controls.Add(Me.chkRooftopDeck)
        Me.Controls.Add(Me.chkLanai)
        Me.Controls.Add(Me.cboBuilding)
        Me.Controls.Add(Me.lblBuilding)
        Me.Controls.Add(Me.lblSlogan)
        Me.Controls.Add(Me.lblBaseRent)
        Me.Controls.Add(Me.txtBaseRent)
        Me.Controls.Add(Me.lblTitle)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Name = "frmLeasing"
        Me.Text = "Haleakela Lofts Leasing Assistant"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lblTitle As Label
    Friend WithEvents txtBaseRent As TextBox
    Friend WithEvents lblBaseRent As Label
    Friend WithEvents lblSlogan As Label
    Friend WithEvents lblBuilding As Label
    Friend WithEvents cboBuilding As ComboBox
    Friend WithEvents chkLanai As CheckBox
    Friend WithEvents chkRooftopDeck As CheckBox
    Friend WithEvents chkNonsmoking As CheckBox
    Friend WithEvents lblRentTitle As Label
    Friend WithEvents lblRent As Label
    Friend WithEvents btnCalculateRent As Button
    Friend WithEvents btnExit As Button
End Class
