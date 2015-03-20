Attribute VB_Name = "Module1"
Sub main()
    Randomize
    Open "testdata.in" For Output As #2
    For i = 1 To 100
        n = Fix(Rnd() * 950) + 1
        m = Fix(Rnd() * 980) + 2
        Print #2, Trim(n); " "; Trim(m)
    Next
    For i = 1 To 100
        n = Fix(Rnd() * 9500) + 1
        m = Fix(Rnd() * 980) + 2
        Print #2, Trim(n); " "; Trim(m)
    Next
    For i = 1 To 100
        n = Fix(Rnd() * 95000) + 1
        m = Fix(Rnd() * 980) + 2
        Print #2, Trim(n); " "; Trim(m)
    Next
    For i = 1 To 200
        n = Fix(Rnd() * 9500000) + 1
        m = Fix(Rnd() * 980) + 2
        Print #2, Trim(n); " "; Trim(m)
    Next
End Sub
