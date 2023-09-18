# Form/Window View - Generated Source Code File 
# Generated by the Ring 1.19 Form Designer
# Date : 18/09/2023
# Time : 19:17:23

Load "stdlibcore.ring"
Load "guilib.ring"

import System.GUI

if IsMainSourceFile() { 
	new App {
		StyleFusion()
		new mainView { win.show() } 
		exec()
	}
}

class mainView from WindowsViewParent
	win = new MainWindow() { 
		move(0,20)
		resize(1247,909)
		setWindowTitle("Teaching Hours Counter")
		setstylesheet("background-color:;") 

		setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_WindowCloseButtonHint | Qt_CustomizeWindowHint) 
		TableWidget1 = new tablewidget(win) {
			move(24,57)
			resize(916,581)
			setstylesheet("color:;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setColumnCount(3)
			setHorizontalHeaderItem(1, new QTableWidgetItem("Type"))
			setHorizontalHeaderItem(2, new QTableWidgetItem("Count"))
			setHorizontalHeaderItem(3, new QTableWidgetItem("Hours"))
			setColumnwidth(1,400)
			setColumnwidth(2,240)
			setColumnwidth(3,250)
			setSelectionBehavior(QAbstractItemView_SelectRows)
			setAlternatingRowColors(True)
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
		Label1 = new label(win) {
			move(955,56)
			resize(279,40)
			setstylesheet("color:;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("Undergraduate (Lectures, Exercise and Labs) :")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
		txtSum = new lineedit(win) {
			move(955,100)
			resize(279,47)
			setstylesheet("color:;background-color:white;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("")
			setTextChangedEvent("")
			setcursorPositionChangedEvent("")
			seteditingFinishedEvent("")
			setreturnPressedEvent("")
			setselectionChangedEvent("")
			settextEditedEvent("")
			
		}
		Label2 = new label(win) {
			move(24,665)
			resize(52,41)
			setstylesheet("color:;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("Hours:")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
		txtHours = new lineedit(win) {
			move(276,665)
			resize(159,47)
			setstylesheet("color:;background-color:white;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("0")
			setTextChangedEvent("")
			setcursorPositionChangedEvent("")
			seteditingFinishedEvent("")
			setreturnPressedEvent("")
			setselectionChangedEvent("")
			settextEditedEvent("")
			
		}
		ListHours = new listwidget(win) {
			move(71,665)
			resize(190,194)
			setstylesheet("color:;background-color:white;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			AddItem("0.0")
			AddItem("0.5")
			AddItem("1.0")
			AddItem("1.5")
			AddItem("2.0")
			AddItem("2.5")
			AddItem("3.0")
			AddItem("3.5")
			AddItem("4.0")
			setcurrentItemChangedEvent("")
			setcurrentRowChangedEvent(Method(:SelectedHoursChanged))
			setcurrentTextChangedEvent("")
			setitemActivatedEvent("")
			setitemChangedEvent("")
			setitemClickedEvent("")
			setitemDoubleClickedEvent("")
			setitemEnteredEvent("")
			setitemPressedEvent("")
			setitemSelectionChangedEvent("")
			
		}
		Button1 = new pushbutton(win) {
			move(276,735)
			resize(159,41)
			setstylesheet("color:;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("AddHours")
			setClickEvent(Method(:AddHours))
			setBtnImage(Button1,"")
			
		}
		Label8 = new label(win) {
			move(24,5)
			resize(82,41)
			setstylesheet("color:;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("Select Type:")
			setAlignment(Qt_AlignLeft |  Qt_AlignVCenter)
		}
	}

# End of the Generated Source Code File...