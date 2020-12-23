using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//using MonoBrick.EV3;//use this to run the example on the EV3
using MonoBrick.NXT;//use this to run the example on the NXT  



namespace Application
{
}

public static class Program
{

    //global variables
    public static int[] wayBack = new int[100];
    public static int i = 0;
    public static int direction = 0;
    public static int currx = 0;
    public static int curry = 0;
    public static int targetx = 2;
    public static int targety = 2;
    static Brick<Sensor, Sensor, Sensor, Sonar> brick;

    //crate struct to keep track of walls
    public struct cell
    {
        public int northWall;
        public int eastWall;
        public int southWall;
        public int westWall;
    }
    // make 2d array for struct (4 by 6 maze dimensions)
    public static cell[,] maze = new cell[4, 6];
 
    public static void wallTracker()
    {
        //if there is a wall 
        if ((brick.Sensor4.ReadDistance()) < 19)
        {
            //store 1 for that cell and direction
            switch (direction)
            {
                case 0: maze[currx,(curry)].northWall = 1; Console.WriteLine("Cell({0}, {1}) there is a wall on NORTH side", currx, curry); break;
                case 1: maze[currx, curry].eastWall = 1; Console.WriteLine("Cell({0}, {1}) there is a wall on EAST side", currx, curry); break;
                case 2: maze[currx,curry].southWall = 1; Console.WriteLine("Cell({0}, {1}) there is a wall on WEST side", currx, curry); break;
                case 3: maze[(currx), (curry)].westWall = 1; Console.WriteLine("Cell({0}, {1}) there is a wall on SOUTH side", currx, curry); break;
                default: break;
            }
        }
        // if there is no wall 
        if ((brick.Sensor4.ReadDistance()) > 19)
        {
            // store 0 for that cell and direction
            switch (direction)
            {
                case 0: maze[(currx), (curry)].northWall = 0; break;
                case 1: maze[(currx), (curry)].eastWall = 0; break;
                case 2: maze[(currx), (curry)].southWall = 0; break;
                case 3: maze[(currx), (curry)].westWall = 0; break;
                default: break;
            }
        }
    }

    // fucntion to align robot once it reaches target cell
    public static void scan()
    {
        for (int z = 0; z < 4; z++)
        {
            turnRight();
            if ((brick.Sensor4.ReadDistance()) < 19)
            {
                align();
            }
        }
    }
    //function to turn back once destination reached
    public static void turningBack(int[] wayBack)
    {
        Console.WriteLine();
        //display the array path back
        Console.Write("The path back is: ");
        for (int i = 0; i < ((wayBack.Length)); i++)
        {
            Console.Write(wayBack[i]);
        }
        Console.WriteLine();
        
        for (int b = 0; b < wayBack.Length; b++)//check each element of array
        {
            //use switch statments to determine what whcih way to turn to go to array element direction
            switch (wayBack[b])
            {
                case 0:
                    if (direction == 1)
                    {
                        turnLeft();

                    }

                    if (direction == 3)
                    {
                        turnRight();
                    }
                    if (direction == 2)
                    {
                        turnLeft();
                        turnLeft();
                    }
                    wayBackForward();
                    break;
                case 1:
                    if (direction == 0)
                    {
                        turnRight();
                    }
                    if (direction == 2)
                    {
                        turnLeft();
                    }

                    if (direction == 3)
                    {
                        turnLeft();
                        turnLeft();
                    }
                    wayBackForward();
                    break;
                case 2:

                    if (direction == 1)
                    {
                        turnRight();
                    }
                    if (direction == 3)
                    {
                        turnLeft();
                    }

                    if (direction == 0)
                    {
                        turnLeft();
                        turnLeft();
                    }
                    wayBackForward();
                    break;
                case 3:
                    if (direction == 0)
                    {
                        turnLeft();

                    }
                    if (direction == 2)
                    {
                        turnRight();
                    }

                    if (direction == 1)
                    {
                        turnLeft();
                        turnLeft();
                    }
                    wayBackForward();
                    break;
                default: break;
            }
        }
    }
    //align function to align robot with wall
    public static void align()
    {
        Console.WriteLine("Aligning.");
        while (Convert.ToInt16(brick.Sensor2.ReadAsString()) == 0 || Convert.ToInt16(brick.Sensor3.ReadAsString()) == 0)
        {
            brick.MotorA.On(35);
            brick.MotorC.On(35);
        }
        
        if (Convert.ToInt16(brick.Sensor2.ReadAsString()) == 1 && Convert.ToInt16(brick.Sensor3.ReadAsString()) == 1)
        {
            brick.MotorA.ResetTacho();
            brick.MotorC.ResetTacho();

            while (brick.MotorC.GetTachoCount() > -92)
            {
                brick.MotorA.On(-30);
                brick.MotorC.On(-30);

            } brick.MotorA.Brake();
            brick.MotorC.Brake();
            System.Threading.Thread.Sleep(500);//pause so tacho can reset properly

        }
    }

    //turn left functoin
    public static void turnLeft()
    {
        Console.WriteLine("Turning left.");
        brick.MotorA.ResetTacho();
        brick.MotorC.ResetTacho();
        while (brick.MotorA.GetTachoCount() < 377)
        {
            brick.MotorA.On(30);
            brick.MotorC.On(-30);      
        }
        brick.MotorA.Brake();
        brick.MotorC.Brake();

        direction--;//decrement diretion when making left rotation

        //if directin is -1 then make it equal to 2 since -1 is not a direction
        if (direction == -1)
        {
            direction = 3;
        }
        Console.WriteLine("Direction = {0}", direction);
        wallTracker();//call wall tracker so it can keep track of wall (store 1 or 0)
        System.Threading.Thread.Sleep(500);

    }
    //turn right function
    public static void turnRight()
    {
        Console.WriteLine("Turning right.");
        brick.MotorA.ResetTacho();
        brick.MotorC.ResetTacho();

        while (brick.MotorC.GetTachoCount() < 374) 
        {
            brick.MotorA.On(-30);
            brick.MotorC.On(30);     
        }
        brick.MotorA.Brake();
        brick.MotorC.Brake();

        direction++;//increment direction when rotating right
        //if direction is 4 make it 0 since 4 is not a direction
        if (direction == 4)
        {
            direction = 0;
        }
        Console.WriteLine("Direction = {0}", direction);
        wallTracker();
        System.Threading.Thread.Sleep(500);

    }
   //go forward one cell function
    public static void goForward()
    {
        brick.MotorA.ResetTacho();
        brick.MotorC.ResetTacho();
        //move up one cell
        while (brick.MotorC.GetTachoCount() < 775)
        {
            brick.MotorA.On(30);
            brick.MotorC.On(30);
        }
        brick.MotorA.Brake();
        brick.MotorC.Brake();
        //statment to increment or decrement x and y postion
        //store opposite value in array then increment
        switch (direction)
        {
            case 0: curry++; wayBack[i] = 2; i++; break;
            case 1: currx++; wayBack[i] = 3; i++; break;
            case 2: curry--; wayBack[i] = 0; i++; break;
            case 3: currx--; wayBack[i] = 1; i++; break;
            default: break;
        }
        Console.WriteLine();
        Console.WriteLine("cell number = ({0}, {1})", currx, curry);
        wallTracker();
        System.Threading.Thread.Sleep(500);
        //once arrived at destination
        if (currx == targetx && curry == targety)
        {
            Console.WriteLine();
            Console.WriteLine("ARRIVED AT DESTINATION ({0}, {1})", currx, curry);
            Console.WriteLine();

            scan();//align
            //face north
            while (direction != 0)
            {
                turnRight();
            }
            Console.WriteLine("Direction = {0}", direction);

            System.Threading.Thread.Sleep(5000);//pause 5 seconds
            //elimaate reduntant moves
            for (int b = 0; b < 50; b++)
            {
                for (int i = 0; i < ((wayBack.Length) - 1); i++)
                {
                    if (wayBack[i] == (wayBack[i + 1] + 2) || wayBack[i + 1] == (wayBack[i] + 2))
                    {
                        wayBack[i] = 99;
                        wayBack[i + 1] = 99;
                    }
                }
                int numToRemove = 99;
                wayBack = wayBack.Where(val => val != numToRemove).ToArray();
            }

            Array.Reverse(wayBack);//reverse array
            turningBack(wayBack);//turn back to origin
            brick.Connection.Close();//shutdown
        }
    }

 //seperate function for moving forward one cell for way back since other forward function has extra operations
    public static void wayBackForward()
    {
        brick.MotorA.ResetTacho();
        brick.MotorC.ResetTacho();

        while (brick.MotorC.GetTachoCount() < 775)
        {
            brick.MotorA.On(30);
            brick.MotorC.On(30);
        }

        brick.MotorA.Brake();
        brick.MotorC.Brake();
        switch (direction)
        {
            case 0: curry++; i++; break;
            case 1: currx++; i++; break;
            case 2: curry--; i++; break;
            case 3: currx--; i++; break;
            default: break;
        }
        Console.WriteLine();
        Console.WriteLine("cell number = ({0}, {1})", currx, curry);

    }

    public static void Main()
    {

        try
        {
            brick = new Brick<Sensor, Sensor, Sensor, Sonar>("COM3");
            // sbyte speed = 0;  
            brick.Connection.Close();
            brick.Connection.Open();

            brick.Sensor4 = new Sonar();
            brick.Sensor3 = new TouchSensor();
            brick.Sensor2 = new TouchSensor();
            //store all array values as 99
            for (int i = 0; i < (wayBack.Length); i++)
            {
                wayBack[i] = 99;
            }
       
            Console.WriteLine("Direction = {0}", direction);
            Console.WriteLine("cell number = ({0}, {1})", currx, curry);
            //follow righth side wall
            while (1==1)//infinte loop
            {
                //align if wall infront
                if ((brick.Sensor4.ReadDistance()) < 19)
                {
                    align();
                }

                turnRight();
                //go forward if no wall infront
                while ((brick.Sensor4.ReadDistance()) > 19)
                {
                    goForward();
                    //align if wall infront
                    if ((brick.Sensor4.ReadDistance()) < 19)
                    {
                        align();
                    }
                    turnRight();
                }

                //keep turing left till no wall infront then move forward
                while ((brick.Sensor4.ReadDistance()) < 19)
                {
                    align();

                    turnLeft();
                }
                goForward();
            }

            //break and close connection
            brick.MotorA.Brake();
            brick.MotorC.Brake();
            brick.Connection.Close();
        }
         //error handling
        catch (Exception e)
        {
            Console.WriteLine("Error: " + e.Message);
            Console.WriteLine("Press any key to end...");
            Console.ReadKey();
        }
    }


}