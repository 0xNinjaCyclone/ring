#================================================#
# This code is generated by Bing Chat (AI)
# Questions by Fayed
#================================================#

# Declare a global variable to store the counter value
counter = 0

# Start a loop that runs until false    
while true 
     # Call showMenu and store its result in choice     
     choice = showMenu() 
     # Check if choice is 1     
     if choice = 1         
          sayHello()      
     else         
          # Check if choice is 2         
          if choice = 2             
               counter()                 
          else             
               # Check if choice is 3             
               if choice = 3                 
                    close()                                  
               else                     
                    see "Invalid choice!" + nl                     
                    ? "Press any key to continue..."
                    give key                    
               ok
          ok
     ok
end

# Define a function to display the main menu and get the user choice
func showMenu()
    # Clear the screen
    system("cls")
    # Print the menu options
    see "Main Menu" + nl
    see "1) Say Hello" + nl
    see "2) Counter" + nl
    see "3) Exit" + nl
    # Get the user input
    ? "Enter your choice: "
    give choice
    # Return the choice as a number
    return number(choice)

# Define a function to handle the say hello option
func sayHello()
    # Get the user name
    ? "Enter your name: "    
    give name
    # Print a greeting message
    see "Hello, " + name + nl
    # Wait for any key to return to the menu   
    ? "Press any key to continue..."
    give key

# Define a function to handle the counter option
func counter()
     # Increment it by one     
     counter++ 
     # Print its value     
     see "Counter value: " + counter + nl 
     # Wait for any key to return to the menu    
     ? "Press any key to continue..."
     give key

# Define a function to handle the exit option    
func close()
     bye 