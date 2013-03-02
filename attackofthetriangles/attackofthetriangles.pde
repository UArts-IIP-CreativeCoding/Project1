// controlling new random triangles

// info for data

float r= random(250); // random red
float g = random(250); // random green
float b = random(250); // random blue
float rs = 1.5; // 
float rpx1 = random (1024);
float rpy1 = random (768);
float rpx2 = random (1024);
float rpy2 = random (768);
float rpx3 = random (1024);
float rpy3 = random (768);

void setup() {
  size(1024, 768);
  background(155);
  frameRate(10);
}

void draw() {
  triangles();
}

// data for program


void key_commands() {
  if (keyPressed) { // controls stroke width
    if (key == 'e') {
     rs++;
    }
    if (key == 'E')
      rs--;
  }
  if (keyPressed) { // controls color
    if (key == 'q' || key == 'Q') {
      r=random(250);
      g=random(250);
      b=random(250);
    }
  }
  if (keyPressed) { // controls random generation of point 1
    if (key == 'w') {
      rpx2++;
      rpy2++;
      rpx3++;
      rpy3++;
    }
    if (keyPressed) {
      if (key == 'W') {
        rpx1--;
        rpy1--;
        rpx2--;
        rpy2--;
        rpx3--;
        rpy3--;
      }
    }
    if (keyPressed) {
      if (key == 'r') {
        background(r++, b);
      }
    }
  }
}

// you can do a "class" for the shapes after you get this into OF!
// yay!


void triangles() { // random triangle generator
    //click the mouse in the bottom left quad and generate random triangles
    key_commands();
    noFill();
    if (mousePressed == true) {  
      noFill();
      stroke(2, r, g, b);
      strokeWeight(rs);
      rpx1=mouseX;
      rpy1=mouseY;
      triangle(rpx1, rpy1, rpx2, rpy2, rpx3, rpy3);
      if(rs < 1){
        rs = 2 ;
      }
    }
  }

