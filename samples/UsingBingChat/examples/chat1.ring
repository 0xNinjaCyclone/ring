#================================================#
# Author: Bing Chat 
# Questions by Fayed
# Note: It's not the perfect code (It just works!)
#================================================#

# Create an object from the Point class
p = new Point

# Set the values of x, y and z
p.setX(10)
p.setY(20)
p.setZ(30)

# Print the values of x, y and z
p.printX()
p.printY()
p.printZ()

# Display the point coordinates
p.display()

# Find and print the maximum value among x, y and z
? "The maximum value is " + p.max()

Class Point
    x = 0
    y = 0
    z = 0

    func setX(value)
        x = value
    end

    func getX()
        return x
    end

    func printX()
        ? "x = " + x
    end

    func setY(value)
        y = value
    end

    func getY()
        return y
    end

    func printY()
        ? "y = " + y
    end

    func setZ(value)
        z = value
    end

    func getZ()
        return z
    end

    func printZ()
        ? "z = " + z
    end

    func display()
        ? "Point: (" + x + ", " + y + ", " + z + ")"
    end

    func max()
        # Compare the numbers and select the maximum value
        if x > y 
            if x > z 
                return x 
            else 
                return z 
            ok 
        else 
            if y > z 
                return y 
            else 
                return z 
            ok 
        ok  
   end    
End    