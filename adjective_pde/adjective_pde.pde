/* 
 Intro to Interactive Programming – Creative Coding
 project 1 - adjective - magnetic
 bk
 bklevence@uarts.edu
 ========
 input:
 
 mouseover  - rub center to excite
 space - color
 UP/DWN - speed
 */

float x;
float y;

float theta = 90; //for loop and rotation variable

int dir; //direction: 0, Stopped; 1, Right; 2, Left
int acc = 1; //speed
int d = 25; //diameter of ellipse
int r = d/2; //radius "~"
float d2 = 100;//diameter of influencing circle
float r2 = d2/2; //radius of "~"
float h, w;
float tail = 5;
int value = 255;
//attempt at using array to change color, couldnt duplicate in oF
/*int[] colors = {
 #6F00FF, #FF004F, #00FF7F, #FFFF00, #2F4F4F
 };*/
int cval;
int i;

void setup() {
  size(1024, 768); //window size
  background(255); //initial background color
  frameRate(60); //setting framerate
  dir = 0; //stopping from animating
  x = (width/2); //setting initial X
  y = (height/2); // setting initial y
}

void draw() {

  mouseOver(); //declaring direction
  moveEllipse(); //checking direction, starting motion.

  fill(0, 4); //gradient tail learned in class 022114
  rect(0, 0, width, height); //gradient tail learned in class 022114
  noStroke(); //no stroke on elements
  drawAoE();
  translate(width/2, height/2); //center 
  //CHAPTER 14: EXAMPLE 14-5: RECTANGLE ROTATING AROUND CENTER
  for (float i = 0; i < TWO_PI; i += .1) { //draw movers around a full circle

    pushMatrix();
    scale(.35); //scale it to .35 to fit screen well
    rotate(theta + i);
    drawEllipse(); //mover
    popMatrix();
  } 

  //inclass crawler demo
  //constrain original mover
  x = constrain(x, .25*width, .75*width);
  y = constrain(y, height/2, .75*height);
  translate(-(width/2), -(height/2));
  if(dir==0){
  fill(200, 15); 
  rect(0, 0, width, height); //lighten background
  }
  /*debug
   println(x);
   println(dir);
   println(mouseX - (.75*width));
   */
}

void drawAoE() {
  if (dir == 0) { //transparent area of influence circles
    d2 = random(0, 100); //if not moving bounce d small
    fill(255, 15); //gradient tail learned in class 022114
    rect(0, 0, width, height); //gradient tail learned in class 022114
  }
  else {
    d2 = random(100, 150); //if moving
  }

  fill(0, 3); //gradient tail learned in class 022114
  ellipse(width/2, height/2, d2, d2); //center influence point
}

void drawEllipse() {  
  fill(value);
  noStroke();
  ellipseMode(CENTER);
  ellipse(x, y, d, d);
}

//inclass 02.14.13
void moveEllipse() {
  if ( dir == 1) {
    x= x + random(tail);
    y= y + random(tail);
  }
  else { 
    if (dir == 2) {
      x= x - random(tail);
      y= y - random(tail);
    }
  }
  if ( x > (.75*width) || x < width/2) {
    dir = 0; //stay
  }
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == UP) {
      tail++;
    } 
    else if (keyCode == DOWN) {
      tail--;
    }
  }
  if (key == 32) {
    colorCycle();
  }

/*  old clear key before changing so they look similar

    if (key == 110) {
    translate(-(width/2), -(height/2));
    fill(255); //gradient tail learned in class 022114
    rect(0, 0, width, height); //gradient tail learned in class 022114
    value = 255;
    dir = 2;
  }
  
 */ 
}

void colorCycle() {
  if (dir==0 && value == 255) {
    //attempt at using array to change color, couldnt duplicate in oF
    //cval = int(random(5)); 
    //value = colors[cval];
    value = #6F00FF;
  }
  else if (dir==0 && value == #6F00FF) {
    value = 255;
  }
}



void mouseOver() {
  //the Tickle example under java examples/topics/interaction helped me understand this better

  /*
  if (abs(mouseX - x) < r && abs(mouseY - y) < r && x <= width/2) {
   dir = 1; //home
   if (abs(mouseX - (.75*width)) < r && abs(mouseY - y) < r && x == (.75*width)) {
   dir = 2; //go home your drunk
   }
   }
   */
  //mouseover center ellipse to influence ring
  if (abs(mouseX - x) < r2 && abs(mouseY - y) < r2 && x <= width/2) {
    dir = 1; //home
  }
  if  (abs(mouseX - (width/2)) < r2 && abs(mouseY - (height/2)) < r2 && x == (.75*width)) {
    dir = 2; //go home your drunk
  }
}

