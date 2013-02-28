// credits
// http://processing.org/reference/
// movement design for "stress"
// brenden moore - uarts 2013

int value = 0;
int circleSize = 50;
float circleReduce = 0;

float xpos, ypos;    // Starting position of shape    

float xspeed = 2.8;  // Speed of the shape
float yspeed = 2.2;  // Speed of the shape

int xdirection = 1;  // Left or Right
int ydirection = 1;  // Top to Bottom

boolean move = false;
boolean[] animation = new boolean[4]; // animation controls background colors

/* boolean animation1 = new boolean;
boolean animation2 = new boolean;
boolean animation3 = new boolean;
boolean animation4 = new boolean;
*/

void setup() {
  size(1024, 768);
  smooth();
  xpos = width/2;
  ypos = height/2;
  for(int i=0;i<animation.length;i++) animation[i] = false; //turns forloop off
}

void draw() {
  // custom function for creating background trail
  trailBackground(50);
  // smaller o - green relaxed
  
  // larger o - red alaert
  if (mousePressed) {
    if(circleSize<251){
      circleSize++;
    }
  }  
  
  stroke(255);
 if(circleSize<251) {
   move = false;
   fill(169, 239, 185);
 }
 else{
   move = true;
   fill(176, 15, 15);
   
 }
 
  if(move){
  // Update the position of the shape
//  xpos = xpos + ( xspeed * xdirection );
//  ypos = ypos + ( yspeed * ydirection );
    xpos = random(width) + ( xspeed * xdirection );
  ypos = random(height) + ( yspeed * ydirection );
  
  // Test to see if the shape exceeds the boundaries of the screen
  // If it does, reverse its direction by multiplying by -1
  if (xpos > width-circleSize/2 || xpos < circleSize/2) {
    xdirection *= -1;
  }
  if (ypos > height-circleSize/2 || ypos < circleSize/2) {
    ydirection *= -1;
  }
  
  // when the circle reaches at the right boundary
  if (xpos > width-circleSize/2){
    animation[0] = true;
  //  circleReduce = 50;
  }
  // when the circle reaches at the left boundary
  if(xpos < circleSize/2){
     animation[1] = true;
  }
 
  // when the circle reaches at the botton boundary
  if (ypos > height-circleSize/2){
     animation[2] = true;
  }
  // when the circle reaches at the Top boundary
  if (ypos < circleSize/2){
     animation[3] = true;
  }
  for(int i=0;i<animation.length;i++){
  if(animation[i]){
    if(circleReduce<25) {
      circleReduce++;
    } else {
      animation[i] = false;
      circleReduce = 0;
    }
  }
  }
  
  
   if (mousePressed != true) {
    circleSize = 60;
    xpos = width/2;
    ypos = height/2;

    for(int i=0;i<animation.length;i++) animation[i] = false; //turns forloop off
   }
   
  }
  
  
//  circleReduce = map(dist(xpos,ypos,width,height),0,width/2,200,0);

 // println(circleReduce);
  
  ellipse(xpos, ypos, circleSize - circleReduce, circleSize - circleReduce);
} 

void trailBackground(int opacity){
  noStroke();
  
  for(int i=0;i<animation.length;i++){ // creating four different background colors
   if(animation[i]){       
   float randomR = random(255);
   float randomG = random(255);
   float randomB = random(255);
     fill(randomR,randomG,randomB,opacity);
   }
  }

  rect(-1,-1,width+1,height+1);
}

//void mouseClicked() {
//  if (value == 0) {
//    background(0);    
//    fill(176, 15, 15);
//    ellipse(width/2, height/2, 250, 250); // larger o
//  }
//  else {
//    value = 0;
//  }
//}

