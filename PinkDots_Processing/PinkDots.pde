float dude = 0;
float ult = 0;
float dudeSomething =1; //top line
float dudeHeight =1;//bottom line


void setup() {

  size(1024, 768);
  smooth();
  frameRate(30);
}


void draw() {

  background(175);


  dude = dude + .07; //speed of dude


  for ( int a = 1; a < 100; a++) // if a is less than 40 
  {   
    float dudeOffset = a* .01;



    float y = cos( dude + dudeOffset) *  height/2 + height/2;
    //
    float x = a * 5 + 250;// // first # effects space between and last effects loc
    noStroke();
    fill(255, 0, 100); 
    ellipse(x, y, 30, 30);
     //
  }

  if (mousePressed && mouseX > width/2 && mouseY > height/2)//bottom right corner

    { ult = ult + .2; //speed of ult
    dude = ult + .09;
      }


  float ultSomething = height/2; //top line
  float ultHeight = height/2;//bottom line

  for ( int a = 1; a < 100; a++) // if a is less than 40 
  {   
    float ultOffset = a* .99;



    float y = cos( ult + ultOffset) *  ultSomething+ ultHeight;
    float x = a * 10 + 10;// space between
    fill(0, 100, 100); 
    rect(x, y, 3, 20);
     //
  }
} 

