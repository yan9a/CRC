'####################################################################
'CRC32 Calculator
'File: CRC32.vb
'WebSite: http://cool-emerald.blogspot.sg/
'License: Creative Commons Attribution-ShareAlike 3.0
'         http://creativecommons.org/licenses/by-sa/3.0/
'Programmer: Yan Naing Aye
'Date: 04 June 2009

Public Class CRC32
    Private Shared CRC32_Tab(255) As UInt32
    Shared Sub New()
        CRC32_InitTable()
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
    Public Shared Function Calculate(ByVal InputString As String, Optional ByVal CRC As UInt32 = 4294967295) As UInt32
        'CRC Order: 32        
        'CRC Poly: 0x04C11DB7 <=> EDB88320
        'Operational initial value:  0xFFFFFFFF 
        'Final xor value: 0xFFFFFFFF
        Dim b() As Byte = Str2Byte(InputString)
        For Each BT As Byte In b
            CRC = (CRC >> 8) Xor CRC32_Tab((CRC And &HFF) Xor System.Convert.ToUInt32(BT))
        Next
        CRC = Not (CRC)
        Return CRC
    End Function
    Public Overloads Shared Function ToString(ByVal CRC As UInt32) As String
        Return Chr(CRC >> 24) & Chr((CRC >> 16) And &HFF) & Chr((CRC >> 8) And &HFF) & Chr(CRC And &HFF)
    End Function
    Private Shared Sub CRC32_InitTable()
        Dim CRC As UInt32
        For i As UInt32 = 0 To 255
            CRC = i
            For j As Integer = 0 To 7
                If (CRC And &H1) = &H1 Then
                    CRC = (CRC >> 1) Xor 3988292384
                Else
                    CRC = CRC >> 1
                End If
            Next
            CRC32_Tab(i) = CRC
        Next
    End Sub
End Class
