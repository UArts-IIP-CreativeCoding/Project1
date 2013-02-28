//dissociative

int x = 1; // beginning amount
int y = 1; // beginning amount
int z = 40; // incremental increase

//true & false control statements to switch from shapes utilizing the keyboard

boolean start = true;
boolean elli = false;
boolean squa = false;

void setup(){
  size(1280, 768);
  noFill();
  rectMode(CORNER);
  background(0);
  colorMode(HSB, width, height, height); //limits defined by width and height for varying colors under HSB range
}

void drawEllipse(){
 translate(width/2, height/2); //transformations of the ellipses are halved, specifying an amount the ellipses are halved after the translate
  for (y=1; y<height+100;y+=z){ //loop y=1 then run that through the height of the ellipse + 100 
  for(x=1; x<width+100;x+=z){ //loop x=1 then run that through the width of the ellipse + 100
  int loc = x+(y*width); //declaration of location is of x is then added by the width of ellipse multipled by x
      stroke(mouseY,mouseX,mouseY); //stroke color is altered by placement of mouse
  fill(0); 
  pushMatrix(); //stacking of ellipses
  rotate(loc); //multiplies the transformations of the ellipses with declared int
   ellipse(mouseX-(width/2),mouseY-(height/2),mouseX/6,mouseY/2); //size of ellipse is then determined by the placement of mouse (move to left shape begins to grow smaller, right bigger, up smaller, down bigger)
  popMatrix(); //end stack
  }
 }

}

void drawRect(){
 translate(width/2, height/2);
  for (y=1; y<height+100;y+=z){
  for(x=1; x<width+100;x+=z){
  int loc = x+(y*width);
  stroke(mouseY,mouseX,mouseY);
  fill(0);  
  pushMatrix();
  rotate(loc);
   rect(mouseX-(width/2),mouseY-(height/2),mouseX/6,mouseY/2);
  popMatrix();
  }
 }

}


void drawLine(){
 translate(width/2, height/2);
  for (y=1; y<height+100;y+=z){
  for(x=1; x<width+100;x+=z){
  int loc = x+(y*width);
  stroke(mouseY,mouseX,mouseY);
  fill(0);  
  pushMatrix();
  rotate(loc);
   line(mouseX-(width/2),mouseY-(height/2),mouseX/6,mouseY/2);
  popMatrix();
  }
 }

}

void draw(){
  if (start == true){  //starting with line pattern
  drawLine();
  }
  else if(elli == true){ //if ellipse is switched, pattern is switched to ellipses
  drawEllipse();
  }
  else if(squa == true){ //if rect is switched, pattern is switched to rects
   drawRect();
  }
}


void keyPressed() {
  
  if (key == 'r' || key == 'R'){ //r resets the sketch
   background(0); 
 }
 
 if (key == '1'){ //1 switches to ellipse
   start = false;
   elli = true;
   squa = false;
 }
 
 if (key == '2'){ //2 switches to rect
   start = false;
   elli = false;
   squa = true;
 }

 if (key == '3'){ //switches to line
   start = true;
   elli= false;
   squa = false;
 }
 
}
