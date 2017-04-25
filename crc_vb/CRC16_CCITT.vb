'####################################################################
'CRC16 CCITT Calculator
'File: CRC16_CCITT.vb
'WebSite: http://cool-emerald.blogspot.sg/
'License: Creative Commons Attribution-ShareAlike 3.0
'         http://creativecommons.org/licenses/by-sa/3.0/
'Programmer: Yan Naing Aye
'Date: 04 June 2009

Public Class CRC16_CCITT
    Private Shared CRC16_CCITT_Tab(255) As UInt16
    Shared Sub New()
        CRC16_CCITT_InitTable()
    End Sub
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
    Public Shared Function Calculate(ByVal InputString As String, Optional ByVal CRC As UInt16 = &HFFFF) As UInt16
        'CRC Order: 16
        'CCITT(recommendation) : F(x)= x16 + x12 + x5 + 1
        'CRC Poly: 0x1021
        'Operational initial value:  0xFFFF         
        'Final xor value: 0
        Dim b() As Byte = Str2Byte(InputString)
        For Each BT As Byte In b
            CRC = (CRC << 8) Xor CRC16_CCITT_Tab((CRC >> 8) Xor System.Convert.ToUInt16(BT))
        Next
        Return CRC
    End Function
    Public Overloads Shared Function ToString(ByVal CRC As UInt16) As String
        Return Chr(CRC >> 8) & Chr(CRC And &HFF)
    End Function
    Private Shared Sub CRC16_CCITT_InitTable()
        Dim CRC As UInt16
        For i As UInt16 = 0 To 255
            CRC = i << 8
            For j As Integer = 0 To 7
                If (CRC And &H8000) = &H8000 Then
                    CRC = (CRC << 1) Xor &H1021
                Else
                    CRC = CRC << 1
                End If
            Next
            CRC16_CCITT_Tab(i) = CRC
        Next
    End Sub
End Class
