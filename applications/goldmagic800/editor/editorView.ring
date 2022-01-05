# Form/Window View - Generated Source Code File 
# Generated by the Ring 1.17 Form Designer
# Date : 05/01/2022
# Time : 13:17:44

Load "stdlibcore.ring"
Load "guilib.ring"

import System.GUI

if IsMainSourceFile() { 
	new App {
		StyleFusion()
		new editorView { win.show() } 
		exec()
	}
}

class editorView from WindowsViewParent
	win = new MainWindow() { 
		move(0,0)
		resize(1264,738)
		setWindowTitle("Gold Magic 800 Level Editor")
		setstylesheet("background-color:#e4ff6c;") 

		setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_WindowMinimizeButtonHint | Qt_WindowCloseButtonHint | Qt_WindowStaysOnTopHint | Qt_CustomizeWindowHint) 

		setWinIcon(win,"gold.ico") 
		Label1 = new label(win) {
			move(20,7)
			resize(425,66)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,20,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("Gold Magic 800 Level Editor")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
		Button1 = new pushbutton(win) {
			move(1071,430)
			resize(174,43)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("Load")
			setClickEvent(Method(:LoadLevel))
			setBtnImage(Button1,"")
			
		}
		ListWidget1 = new listwidget(win) {
			move(1074,195)
			resize(174,223)
			setstylesheet("color:black;background-color:white;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,16,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			AddItem("Player")
			AddItem("Ground")
			AddItem("Wall")
			AddItem("Door")
			AddItem("GoldGround")
			AddItem("Door2")
			AddItem("GoldCube")
			AddItem("Door3")
			AddItem("Door4")
			AddItem("Door5")
			AddItem("Door6")
			AddItem("Door7")
			AddItem("Door8")
			AddItem("Door9")
			AddItem("Door10")
			AddItem("Door11")
			AddItem("Door12")
			AddItem("Door13")
			AddItem("Door14")
			AddItem("Door15")
			AddItem("Door16")
			AddItem("GoldMark")
			AddItem("PathMark")
			setcurrentRow(3,2)
			setcurrentItemChangedEvent("")
			setcurrentRowChangedEvent("")
			setcurrentTextChangedEvent("")
			setitemActivatedEvent("")
			setitemChangedEvent("")
			setitemClickedEvent("")
			setitemDoubleClickedEvent("")
			setitemEnteredEvent("")
			setitemPressedEvent("")
			setitemSelectionChangedEvent("")
			
		}
		TableWidget1 = new tablewidget(win) {
			move(20,77)
			resize(1030,625)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,16,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setRowCount(20)
			setColumnCount(20)
			setHorizontalHeaderItem(1, new QTableWidgetItem("1"))
			setHorizontalHeaderItem(2, new QTableWidgetItem("2"))
			setHorizontalHeaderItem(3, new QTableWidgetItem("3"))
			setHorizontalHeaderItem(4, new QTableWidgetItem("4"))
			setHorizontalHeaderItem(5, new QTableWidgetItem("5"))
			setHorizontalHeaderItem(6, new QTableWidgetItem("6"))
			setHorizontalHeaderItem(7, new QTableWidgetItem("7"))
			setHorizontalHeaderItem(8, new QTableWidgetItem("8"))
			setHorizontalHeaderItem(9, new QTableWidgetItem("9"))
			setHorizontalHeaderItem(10, new QTableWidgetItem("10"))
			setHorizontalHeaderItem(11, new QTableWidgetItem("11"))
			setHorizontalHeaderItem(12, new QTableWidgetItem("12"))
			setHorizontalHeaderItem(13, new QTableWidgetItem("13"))
			setHorizontalHeaderItem(14, new QTableWidgetItem("14"))
			setHorizontalHeaderItem(15, new QTableWidgetItem("15"))
			setHorizontalHeaderItem(16, new QTableWidgetItem("16"))
			setHorizontalHeaderItem(17, new QTableWidgetItem("17"))
			setHorizontalHeaderItem(18, new QTableWidgetItem("18"))
			setHorizontalHeaderItem(19, new QTableWidgetItem("19"))
			setHorizontalHeaderItem(20, new QTableWidgetItem("20"))
			setColumnwidth(1,50)
			setColumnwidth(2,50)
			setColumnwidth(3,50)
			setColumnwidth(4,50)
			setColumnwidth(5,50)
			setColumnwidth(6,50)
			setColumnwidth(7,50)
			setColumnwidth(8,50)
			setColumnwidth(9,50)
			setColumnwidth(10,50)
			setColumnwidth(11,50)
			setColumnwidth(12,50)
			setColumnwidth(13,50)
			setColumnwidth(14,50)
			setColumnwidth(15,50)
			setColumnwidth(16,50)
			setColumnwidth(17,50)
			setColumnwidth(18,50)
			setColumnwidth(19,50)
			setColumnwidth(20,50)
			setSelectionBehavior(QAbstractItemView_SelectItems)
			setAlternatingRowColors(False)
			setcellActivatedEvent("")
			setcellChangedEvent("")
			setcellClickedEvent("")
			setcellDoubleClickedEvent("")
			setcellEnteredEvent("")
			setcellPressedEvent("")
			setcurrentCellChangedEvent("")
			setcurrentItemChangedEvent("")
			setitemActivatedEvent("")
			setitemChangedEvent("")
			setitemClickedEvent("")
			setitemDoubleClickedEvent("")
			setitemEnteredEvent("")
			setitemPressedEvent("")
			setitemSelectionChangedEvent("")
			
		}
		Button5 = new pushbutton(win) {
			move(1071,483)
			resize(174,43)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("Save As")
			setClickEvent(Method(:SaveLevel))
			setBtnImage(Button5,"")
			
		}
		Button6 = new pushbutton(win) {
			move(1071,536)
			resize(174,43)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("Update")
			setClickEvent(Method(:UpdateLevel))
			setBtnImage(Button6,"")
			
		}
		lblFile = new label(win) {
			move(473,14)
			resize(827,46)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,16,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("File : ")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
		Button8 = new pushbutton(win) {
			move(1071,589)
			resize(174,43)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("Clear")
			setClickEvent(Method(:Clear))
			setBtnImage(Button8,"")
			
		}
		Button10 = new pushbutton(win) {
			move(1071,642)
			resize(174,43)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("Close")
			setClickEvent(Method(:Close))
			setBtnImage(Button10,"")
			
		}
		Label3 = new label(win) {
			move(1090,80)
			resize(134,27)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,16,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("GM Count")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
		LabelGMCount = new label(win) {
			move(1092,128)
			resize(123,40)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0")
			setfont(oFont)
			oFont.delete()
			setText("")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
	}

# End of the Generated Source Code File...