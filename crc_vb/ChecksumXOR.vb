'####################################################################
'Checksum (XOR) Calculator
'File: ChecksumXOR.vb
'WebSite: http://cool-emerald.blogspot.sg/
'License: Creative Commons Attribution-ShareAlike 3.0
'         http://creativecommons.org/licenses/by-sa/3.0/
'Programmer: Yan Naing Aye
'Date: 04 June 2009

Public Class ChecksumXOR
    Public Shared Function Str2Byte(ByVal str As String) As Byte()
        'Dim ba() As Byte = System.Text.Encoding.ASCII.GetBytes(str)
        Dim ba() As Byte
        Try
            ReDim ba(str.Length - 1)
            For i As Integer = 0 To UBound(ba)
                ba(i) = Asc(str(i))
            Next
        Catch ex As Exception
            ReDim ba(0)
            ba(0) = 0
        End Try
        Return ba
    End Function
    Public Shared Function Calculate(ByVal InputString As String) As Byte
        'Checksum: Xor of all bytes
        Dim CS As Byte = &H0
        Dim b() As Byte = Str2Byte(InputString)
        For Each BT As Byte In b
            CS = CS Xor BT
        Next
        Return CS
    End Function
End Class
