Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("500") 'отправляем
        SerialPort1.Write("D") 'отправляем
        SerialPort1.Close() 'закрываем
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles Me.Load
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("i") 'отправляем
        SerialPort1.Close() 'закрываем
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("S") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer1.Start() 'белый   
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("S") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer2.Start() 'R
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("S") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer3.Start() 'B
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("S") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer4.Start() 'G
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("500") 'отправляем
        SerialPort1.Close() 'закрываем

    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("6") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer1.Stop()
    End Sub

    Private Sub Timer2_Tick(sender As Object, e As EventArgs) Handles Timer2.Tick
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("2") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer2.Stop()
    End Sub

    Private Sub Timer3_Tick(sender As Object, e As EventArgs) Handles Timer3.Tick
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("3") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer3.Stop()
    End Sub

    Private Sub Timer4_Tick(sender As Object, e As EventArgs) Handles Timer4.Tick
        SerialPort1.Open() 'открываем порт
        SerialPort1.Write("1") 'отправляем
        SerialPort1.Close() 'закрываем
        Timer4.Stop()
    End Sub
End Class
