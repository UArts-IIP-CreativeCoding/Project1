
//arrays for the circle
int [] xpos = new int[50];
int [] ypos = new int[50];

float r= 0.0;
float g= 0.0;
float b= 0.0;
float n;
float o;
float p;

void setup() {
  size(1052, 800);
  frameRate = 60;
  smooth(); 
  background(0);

  //initialize array
  for (int i = 0; i < xpos.length; i++) {
    xpos[i] = 0;
    ypos[i] = 0;
  }
}


void draw() {
  
   for (int i = 0; i < xpos.length-1; i++) {
      xpos[i] = xpos[i+1];
      ypos[i] = ypos[i+1];
    }

    xpos[xpos.length-1] = mouseX;
    ypos[ypos.length-1] = mouseY;



  //Squished Grid
  if (mousePressed) {

    //Color Noise
    r = r + .045;
    float n = noise(r) * width/7.5;
    g = g + .035;
    float o = noise(g) * width/7.5;
    b = b + .025;
    float p = noise(b) * width/7.5;

    if (mouseX < width/3) {
      n = 180;
    }
    if ((mouseX > width/3) && (mouseX < 2*width/3)) {
      o = 180;
    }
    if (mouseX > 2*width/3) {
      p = 180;
    }


    background(n, o, p);

    //Vertical Squished Lines
    for (int y = height*-1; y < mouseY; y += width/50) {
      stroke(255);
      //bezier(0,y,mouseX,mouseY,mouseX,mouseY,width,y);
      line(0, y, mouseX, mouseY-height/2+y);
      line(mouseX, mouseY-height/2+y, width, y);
    }
    for (int y = mouseY; y < height*2; y += width/50) {
      stroke(255);
      //bezier(0,y,mouseX,mouseY,mouseX,mouseY,width,y);
      line(0, y, mouseX, mouseY-height/2+y);
      line(mouseX, mouseY-height/2+y, width, y);
    }


    //Horizontal Squished Lines
    for (int x = height*-1; x < mouseX; x += width/50) {
      stroke(255);
      line(x, 0, mouseX-width/2+x, mouseY);
      line(mouseX-width/2+x, mouseY, x, height);
    }
    for (int x = mouseX; x < height*2; x += width/50) {
      stroke(255);
      line(x, 0, mouseX-width/2+x, mouseY);
      line(mouseX-width/2+x, mouseY, x, height);
    }

    //array stuff
   /* for (int i = 0; i < xpos.length-1; i++) {
      xpos[i] = xpos[i+1];
      ypos[i] = ypos[i+1];
    }

    xpos[xpos.length-1] = mouseX;
    ypos[ypos.length-1] = mouseY; */

    for (int i = 0; i < xpos.length; i++) {
      noStroke();
      fill(n+190-i*5, o+20, p+50);
      ellipse(xpos[i], ypos[i], i, i);
    }
  }


  //Flat Grid
  if (!mousePressed) {


    /*   if(n > 0){
     n -= 0.1; 
     }
     if(o > 0){
     o -= 0.1;
     }
     if(p > 0){
     p -= 0.1;
     }*/
    while (n > 0) {
      n = n - .001;
    }
    while (o > 0) {
      o = o - .001;
    }
    while (p > 0) {
      p = p - .001;
    }

    background(n, o, p);


    //Horizontal Lines
    for (int y = 0; y < height; y += width/50) {
      stroke(255);
      line(0, y, width, y);
    }

    //Vertical Lines
    for (int x = 0; x < width; x += width/50) {
      stroke(255);
      line(x, 0, x, height);
    }
 /*   noStroke();
    fill(255, 0, 0);
    ellipse(mouseX, mouseY, 40, 40); */
    
    for (int i = 0; i < xpos.length; i++) {
      noStroke();
      fill(n+i*5);
      ellipse(xpos[i], ypos[i], i+20, i+20);
    }
  }
}


