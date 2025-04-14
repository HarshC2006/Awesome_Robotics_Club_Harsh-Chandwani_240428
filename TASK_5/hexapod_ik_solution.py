import math

def inverse_kinematics(x,y,z):
    # Defining the lengths of the robot's leg segments (coxa, femur, tibia)
    L1=5.0 #coxa
    L2=10.0 #femur
    L3=15.0 #tibia

    # Projecting the distance onto the X-Y plane and calculating the radial distance
    r=math.sqrt(x*x+y*y)

    #Defining some modified radial distances required to solve the problem
    r_modified = r-L1
    r_req = math.sqrt(r_modified**2+z**2)

    try:
        # Calculating the required joint angles based on the diagram provided in the recruitment tasks
        gamma = 180 - math.degrees(math.acos((L2 ** 2 + L3 ** 2 - r_req ** 2) / (2 * L2 * L3)))
        alpha = math.degrees(math.atan2(y, x))
        #Here, the beta angle can have both positive and negative values. Therefore, for each set of coordinates, two sets of angles can be obtained.
        beta = math.degrees(math.acos((r_req ** 2 + L2 ** 2 - L3 ** 2) / (2 * r_req * L2)))

        # Displaying the computed joint angles for the leg mechanism, rounded to 4 decimal places
        return round(alpha, 2), round(beta, 2), round(gamma, 2)

    except ValueError as e:
        return "Error: Coordinates are out of reach."



def test_inverse_kinematics():
    test1 = inverse_kinematics(27.07,0.0,7.07)
    test2 = inverse_kinematics(29.97,1.04,.52)
    test3 = inverse_kinematics(29.9,0.0,0.0)
    test4 = inverse_kinematics(31.4,0.9,7.9)
    test5 = inverse_kinematics(3.4,3.4,-20.9)
    
    print(test1)
    print(test2)
    print(test3)
    print(test4)
    print(test5)
    
test_inverse_kinematics()
    
    


