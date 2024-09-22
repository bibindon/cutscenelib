xof 0303txt 0032

template AnimTicksPerSecond {
  <9E415A43-7BA6-4a73-8743-B73D47E88476>
  DWORD AnimTicksPerSecond;
}

Frame Root {
  FrameTransformMatrix {
     1.000000, 0.000000, 0.000000, 0.000000,
     0.000000,-0.000000, 1.000000, 0.000000,
     0.000000, 1.000000, 0.000000, 0.000000,
     0.000000, 0.000000, 0.000000, 1.000000;;
  }
  Frame Cube {
    FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
    }
    Mesh { // Cube mesh
      24;
      -1.000000;-1.000000;-0.009899;,
      -1.000000;-1.000000; 1.990101;,
      -1.000000; 1.000000; 1.990101;,
      -1.000000; 1.000000;-0.009899;,
      -1.000000; 1.000000;-0.009899;,
      -1.000000; 1.000000; 1.990101;,
       1.000000; 1.000000; 1.990101;,
       1.000000; 1.000000;-0.009899;,
       1.000000; 1.000000;-0.009899;,
       1.000000; 1.000000; 1.990101;,
       1.000000;-1.000000; 1.990101;,
       1.000000;-1.000000;-0.009899;,
       1.000000;-1.000000;-0.009899;,
       1.000000;-1.000000; 1.990101;,
      -1.000000;-1.000000; 1.990101;,
      -1.000000;-1.000000;-0.009899;,
      -1.000000; 1.000000;-0.009899;,
       1.000000; 1.000000;-0.009899;,
       1.000000;-1.000000;-0.009899;,
      -1.000000;-1.000000;-0.009899;,
       1.000000; 1.000000; 1.990101;,
      -1.000000; 1.000000; 1.990101;,
      -1.000000;-1.000000; 1.990101;,
       1.000000;-1.000000; 1.990101;;
      6;
      4;3,2,1,0;,
      4;7,6,5,4;,
      4;11,10,9,8;,
      4;15,14,13,12;,
      4;19,18,17,16;,
      4;23,22,21,20;;
      MeshNormals { // Cube normals
        6;
        -1.000000;-0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
         1.000000;-0.000000; 0.000000;,
         0.000000;-1.000000; 0.000000;,
         0.000000; 0.000000;-1.000000;,
         0.000000;-0.000000; 1.000000;;
        6;
        4;0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;;
      } // End of Cube normals
      MeshTextureCoords { // Cube UV coordinates
        24;
         0.666667; 0.666667;,
         0.333333; 0.666667;,
         0.333333; 1.000000;,
         0.666667; 1.000000;,
         0.333333; 0.333333;,
         0.000000; 0.333333;,
         0.000000; 0.666667;,
         0.333333; 0.666667;,
         0.333333; 0.666667;,
         0.000000; 0.666667;,
         0.000000; 1.000000;,
         0.333333; 1.000000;,
         0.333333; 0.333333;,
         0.333333; 0.666667;,
         0.666667; 0.666667;,
         0.666667; 0.333333;,
         1.000000; 0.666667;,
         0.666667; 0.666667;,
         0.666667; 1.000000;,
         1.000000; 1.000000;,
         0.333333; 0.333333;,
         0.333333; 0.000000;,
         0.000000; 0.000000;,
         0.000000; 0.333333;;
      } // End of Cube UV coordinates
      MeshMaterialList { // Cube material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;
        Material Material {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
          TextureFilename {"tex1.png";}
        }
      } // End of Cube material list
    } // End of Cube mesh
  } // End of Cube
} // End of Root
AnimTicksPerSecond {
  60;
}
AnimationSet CubeAction {
  Animation {
    {Cube}
    AnimationKey { // Rotation
      0;
      180;
      0;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      1;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      2;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      3;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      4;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      5;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      6;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      7;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      8;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      9;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      10;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      11;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      12;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      13;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      14;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      15;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      16;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      17;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      18;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      19;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      20;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      21;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      22;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      23;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      24;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      25;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      26;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      27;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      28;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      29;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      30;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      31;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      32;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      33;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      34;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      35;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      36;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      37;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      38;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      39;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      40;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      41;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      42;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      43;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      44;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      45;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      46;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      47;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      48;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      49;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      50;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      51;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      52;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      53;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      54;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      55;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      56;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      57;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      58;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      59;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      60;4;-0.999962,-0.008706, 0.000000, 0.000000;;,
      61;4;-0.999391,-0.034900, 0.000000, 0.000000;;,
      62;4;-0.996998,-0.077430, 0.000000, 0.000000;;,
      63;4;-0.991138,-0.132834, 0.000000, 0.000000;;,
      64;4;-0.980785,-0.195090, 0.000000, 0.000000;;,
      65;4;-0.966526,-0.256570, 0.000000, 0.000000;;,
      66;4;-0.950737,-0.309999, 0.000000, 0.000000;;,
      67;4;-0.936672,-0.350207, 0.000000, 0.000000;;,
      68;4;-0.927176,-0.374626, 0.000000, 0.000000;;,
      69;4;-0.923880,-0.382683, 0.000000, 0.000000;;,
      70;4;-0.924706,-0.380683, 0.000000, 0.000000;;,
      71;4;-0.927176,-0.374626, 0.000000, 0.000000;;,
      72;4;-0.931218,-0.364462, 0.000000, 0.000000;;,
      73;4;-0.936672,-0.350207, 0.000000, 0.000000;;,
      74;4;-0.943289,-0.331973, 0.000000, 0.000000;;,
      75;4;-0.950737,-0.309999, 0.000000, 0.000000;;,
      76;4;-0.958624,-0.284676, 0.000000, 0.000000;;,
      77;4;-0.966526,-0.256570, 0.000000, 0.000000;;,
      78;4;-0.974031,-0.226415, 0.000000, 0.000000;;,
      79;4;-0.980785,-0.195090, 0.000000, 0.000000;;,
      80;4;-0.986533,-0.163565, 0.000000, 0.000000;;,
      81;4;-0.991138,-0.132834, 0.000000, 0.000000;;,
      82;4;-0.994594,-0.103844, 0.000000, 0.000000;;,
      83;4;-0.996998,-0.077430, 0.000000, 0.000000;;,
      84;4;-0.998526,-0.054277, 0.000000, 0.000000;;,
      85;4;-0.999391,-0.034899, 0.000000, 0.000000;;,
      86;4;-0.999807,-0.019643, 0.000000, 0.000000;;,
      87;4;-0.999962,-0.008706, 0.000000, 0.000000;;,
      88;4;-0.999998,-0.002164, 0.000000, 0.000000;;,
      89;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      90;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      91;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      92;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      93;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      94;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      95;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      96;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      97;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      98;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      99;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      100;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      101;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      102;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      103;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      104;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      105;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      106;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      107;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      108;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      109;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      110;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      111;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      112;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      113;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      114;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      115;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      116;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      117;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      118;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      119;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      120;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      121;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      122;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      123;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      124;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      125;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      126;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      127;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      128;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      129;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      130;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      131;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      132;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      133;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      134;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      135;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      136;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      137;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      138;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      139;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      140;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      141;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      142;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      143;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      144;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      145;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      146;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      147;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      148;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      149;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      150;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      151;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      152;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      153;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      154;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      155;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      156;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      157;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      158;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      159;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      160;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      161;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      162;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      163;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      164;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      165;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      166;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      167;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      168;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      169;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      170;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      171;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      172;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      173;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      174;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      175;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      176;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      177;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      178;4;-1.000000, 0.000000, 0.000000, 0.000000;;,
      179;4;-1.000000, 0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { // Scale
      1;
      180;
      0;3; 1.000000, 1.000000, 1.000000;;,
      1;3; 1.000000, 1.000000, 1.000000;;,
      2;3; 1.000000, 1.000000, 1.000000;;,
      3;3; 1.000000, 1.000000, 1.000000;;,
      4;3; 1.000000, 1.000000, 1.000000;;,
      5;3; 1.000000, 1.000000, 1.000000;;,
      6;3; 1.000000, 1.000000, 1.000000;;,
      7;3; 1.000000, 1.000000, 1.000000;;,
      8;3; 1.000000, 1.000000, 1.000000;;,
      9;3; 1.000000, 1.000000, 1.000000;;,
      10;3; 1.000000, 1.000000, 1.000000;;,
      11;3; 1.000000, 1.000000, 1.000000;;,
      12;3; 1.000000, 1.000000, 1.000000;;,
      13;3; 1.000000, 1.000000, 1.000000;;,
      14;3; 1.000000, 1.000000, 1.000000;;,
      15;3; 1.000000, 1.000000, 1.000000;;,
      16;3; 1.000000, 1.000000, 1.000000;;,
      17;3; 1.000000, 1.000000, 1.000000;;,
      18;3; 1.000000, 1.000000, 1.000000;;,
      19;3; 1.000000, 1.000000, 1.000000;;,
      20;3; 1.000000, 1.000000, 1.000000;;,
      21;3; 1.000000, 1.000000, 1.000000;;,
      22;3; 1.000000, 1.000000, 1.000000;;,
      23;3; 1.000000, 1.000000, 1.000000;;,
      24;3; 1.000000, 1.000000, 1.000000;;,
      25;3; 1.000000, 1.000000, 1.000000;;,
      26;3; 1.000000, 1.000000, 1.000000;;,
      27;3; 1.000000, 1.000000, 1.000000;;,
      28;3; 1.000000, 1.000000, 1.000000;;,
      29;3; 1.000000, 1.000000, 1.000000;;,
      30;3; 1.000000, 1.000000, 1.000000;;,
      31;3; 1.000000, 1.000000, 1.000000;;,
      32;3; 1.000000, 1.000000, 1.000000;;,
      33;3; 1.000000, 1.000000, 1.000000;;,
      34;3; 1.000000, 1.000000, 1.000000;;,
      35;3; 1.000000, 1.000000, 1.000000;;,
      36;3; 1.000000, 1.000000, 1.000000;;,
      37;3; 1.000000, 1.000000, 1.000000;;,
      38;3; 1.000000, 1.000000, 1.000000;;,
      39;3; 1.000000, 1.000000, 1.000000;;,
      40;3; 1.000000, 1.000000, 1.000000;;,
      41;3; 1.000000, 1.000000, 1.000000;;,
      42;3; 1.000000, 1.000000, 1.000000;;,
      43;3; 1.000000, 1.000000, 1.000000;;,
      44;3; 1.000000, 1.000000, 1.000000;;,
      45;3; 1.000000, 1.000000, 1.000000;;,
      46;3; 1.000000, 1.000000, 1.000000;;,
      47;3; 1.000000, 1.000000, 1.000000;;,
      48;3; 1.000000, 1.000000, 1.000000;;,
      49;3; 1.000000, 1.000000, 1.000000;;,
      50;3; 1.000000, 1.000000, 1.000000;;,
      51;3; 1.000000, 1.000000, 1.000000;;,
      52;3; 1.000000, 1.000000, 1.000000;;,
      53;3; 1.000000, 1.000000, 1.000000;;,
      54;3; 1.000000, 1.000000, 1.000000;;,
      55;3; 1.000000, 1.000000, 1.000000;;,
      56;3; 1.000000, 1.000000, 1.000000;;,
      57;3; 1.000000, 1.000000, 1.000000;;,
      58;3; 1.000000, 1.000000, 1.000000;;,
      59;3; 1.000000, 1.000000, 1.000000;;,
      60;3; 1.000000, 1.000000, 1.000000;;,
      61;3; 1.000000, 1.000000, 1.000000;;,
      62;3; 1.000000, 1.000000, 1.000000;;,
      63;3; 1.000000, 1.000000, 1.000000;;,
      64;3; 1.000000, 1.000000, 1.000000;;,
      65;3; 1.000000, 1.000000, 1.000000;;,
      66;3; 1.000000, 1.000000, 1.000000;;,
      67;3; 1.000000, 1.000000, 1.000000;;,
      68;3; 1.000000, 1.000000, 1.000000;;,
      69;3; 1.000000, 1.000000, 1.000000;;,
      70;3; 1.000000, 1.000000, 1.000000;;,
      71;3; 1.000000, 1.000000, 1.000000;;,
      72;3; 1.000000, 1.000000, 1.000000;;,
      73;3; 1.000000, 1.000000, 1.000000;;,
      74;3; 1.000000, 1.000000, 1.000000;;,
      75;3; 1.000000, 1.000000, 1.000000;;,
      76;3; 1.000000, 1.000000, 1.000000;;,
      77;3; 1.000000, 1.000000, 1.000000;;,
      78;3; 1.000000, 1.000000, 1.000000;;,
      79;3; 1.000000, 1.000000, 1.000000;;,
      80;3; 1.000000, 1.000000, 1.000000;;,
      81;3; 1.000000, 1.000000, 1.000000;;,
      82;3; 1.000000, 1.000000, 1.000000;;,
      83;3; 1.000000, 1.000000, 1.000000;;,
      84;3; 1.000000, 1.000000, 1.000000;;,
      85;3; 1.000000, 1.000000, 1.000000;;,
      86;3; 1.000000, 1.000000, 1.000000;;,
      87;3; 1.000000, 1.000000, 1.000000;;,
      88;3; 1.000000, 1.000000, 1.000000;;,
      89;3; 1.000000, 1.000000, 1.000000;;,
      90;3; 1.000000, 1.000000, 1.000000;;,
      91;3; 1.000000, 1.000000, 1.000000;;,
      92;3; 1.000000, 1.000000, 1.000000;;,
      93;3; 1.000000, 1.000000, 1.000000;;,
      94;3; 1.000000, 1.000000, 1.000000;;,
      95;3; 1.000000, 1.000000, 1.000000;;,
      96;3; 1.000000, 1.000000, 1.000000;;,
      97;3; 1.000000, 1.000000, 1.000000;;,
      98;3; 1.000000, 1.000000, 1.000000;;,
      99;3; 1.000000, 1.000000, 1.000000;;,
      100;3; 1.000000, 1.000000, 1.000000;;,
      101;3; 1.000000, 1.000000, 1.000000;;,
      102;3; 1.000000, 1.000000, 1.000000;;,
      103;3; 1.000000, 1.000000, 1.000000;;,
      104;3; 1.000000, 1.000000, 1.000000;;,
      105;3; 1.000000, 1.000000, 1.000000;;,
      106;3; 1.000000, 1.000000, 1.000000;;,
      107;3; 1.000000, 1.000000, 1.000000;;,
      108;3; 1.000000, 1.000000, 1.000000;;,
      109;3; 1.000000, 1.000000, 1.000000;;,
      110;3; 1.000000, 1.000000, 1.000000;;,
      111;3; 1.000000, 1.000000, 1.000000;;,
      112;3; 1.000000, 1.000000, 1.000000;;,
      113;3; 1.000000, 1.000000, 1.000000;;,
      114;3; 1.000000, 1.000000, 1.000000;;,
      115;3; 1.000000, 1.000000, 1.000000;;,
      116;3; 1.000000, 1.000000, 1.000000;;,
      117;3; 1.000000, 1.000000, 1.000000;;,
      118;3; 1.000000, 1.000000, 1.000000;;,
      119;3; 1.000000, 1.000000, 1.000000;;,
      120;3; 1.000000, 1.000000, 1.000000;;,
      121;3; 1.000000, 1.000000, 1.000000;;,
      122;3; 1.000000, 1.000000, 1.000000;;,
      123;3; 1.000000, 1.000000, 1.000000;;,
      124;3; 1.000000, 1.000000, 1.000000;;,
      125;3; 1.000000, 1.000000, 1.000000;;,
      126;3; 1.000000, 1.000000, 1.000000;;,
      127;3; 1.000000, 1.000000, 1.000000;;,
      128;3; 1.000000, 1.000000, 1.000000;;,
      129;3; 1.000000, 1.000000, 1.000000;;,
      130;3; 1.000000, 1.000000, 1.000000;;,
      131;3; 1.000000, 1.000000, 1.000000;;,
      132;3; 1.000000, 1.000000, 1.000000;;,
      133;3; 1.000000, 1.000000, 1.000000;;,
      134;3; 1.000000, 1.000000, 1.000000;;,
      135;3; 1.000000, 1.000000, 1.000000;;,
      136;3; 1.000000, 1.000000, 1.000000;;,
      137;3; 1.000000, 1.000000, 1.000000;;,
      138;3; 1.000000, 1.000000, 1.000000;;,
      139;3; 1.000000, 1.000000, 1.000000;;,
      140;3; 1.000000, 1.000000, 1.000000;;,
      141;3; 1.000000, 1.000000, 1.000000;;,
      142;3; 1.000000, 1.000000, 1.000000;;,
      143;3; 1.000000, 1.000000, 1.000000;;,
      144;3; 1.000000, 1.000000, 1.000000;;,
      145;3; 1.000000, 1.000000, 1.000000;;,
      146;3; 1.000000, 1.000000, 1.000000;;,
      147;3; 1.000000, 1.000000, 1.000000;;,
      148;3; 1.000000, 1.000000, 1.000000;;,
      149;3; 1.000000, 1.000000, 1.000000;;,
      150;3; 1.000000, 1.000000, 1.000000;;,
      151;3; 1.000000, 1.000000, 1.000000;;,
      152;3; 1.000000, 1.000000, 1.000000;;,
      153;3; 1.000000, 1.000000, 1.000000;;,
      154;3; 1.000000, 1.000000, 1.000000;;,
      155;3; 1.000000, 1.000000, 1.000000;;,
      156;3; 1.000000, 1.000000, 1.000000;;,
      157;3; 1.000000, 1.000000, 1.000000;;,
      158;3; 1.000000, 1.000000, 1.000000;;,
      159;3; 1.000000, 1.000000, 1.000000;;,
      160;3; 1.000000, 1.000000, 1.000000;;,
      161;3; 1.000000, 1.000000, 1.000000;;,
      162;3; 1.000000, 1.000000, 1.000000;;,
      163;3; 1.000000, 1.000000, 1.000000;;,
      164;3; 1.000000, 1.000000, 1.000000;;,
      165;3; 1.000000, 1.000000, 1.000000;;,
      166;3; 1.000000, 1.000000, 1.000000;;,
      167;3; 1.000000, 1.000000, 1.000000;;,
      168;3; 1.000000, 1.000000, 1.000000;;,
      169;3; 1.000000, 1.000000, 1.000000;;,
      170;3; 1.000000, 1.000000, 1.000000;;,
      171;3; 1.000000, 1.000000, 1.000000;;,
      172;3; 1.000000, 1.000000, 1.000000;;,
      173;3; 1.000000, 1.000000, 1.000000;;,
      174;3; 1.000000, 1.000000, 1.000000;;,
      175;3; 1.000000, 1.000000, 1.000000;;,
      176;3; 1.000000, 1.000000, 1.000000;;,
      177;3; 1.000000, 1.000000, 1.000000;;,
      178;3; 1.000000, 1.000000, 1.000000;;,
      179;3; 1.000000, 1.000000, 1.000000;;;
    }
    AnimationKey { // Position
      2;
      180;
      0;3; 0.000000, 0.000000, 0.446501;;,
      1;3; 0.000000, 0.000000, 0.851786;;,
      2;3; 0.000000, 0.000000, 1.213593;;,
      3;3; 0.000000, 0.000000, 1.530507;;,
      4;3; 0.000000, 0.000000, 1.802193;;,
      5;3; 0.000000, 0.000000, 2.029562;;,
      6;3; 0.000000, 0.000000, 2.214794;;,
      7;3; 0.000000, 0.000000, 2.361221;;,
      8;3; 0.000000, 0.000000, 2.473071;;,
      9;3; 0.000000, 0.000000, 2.555126;;,
      10;3; 0.000000, 0.000000, 2.612376;;,
      11;3; 0.000000, 0.000000, 2.649704;;,
      12;3; 0.000000, 0.000000, 2.671658;;,
      13;3; 0.000000, 0.000000, 2.682304;;,
      14;3; 0.000000, 0.000000, 2.685163;;,
      15;3; 0.000000, 0.000000, 2.658798;;,
      16;3; 0.000000, 0.000000, 2.579098;;,
      17;3; 0.000000, 0.000000, 2.446482;;,
      18;3; 0.000000, 0.000000, 2.263711;;,
      19;3; 0.000000, 0.000000, 2.036554;;,
      20;3; 0.000000, 0.000000, 1.774191;;,
      21;3; 0.000000, 0.000000, 1.489078;;,
      22;3; 0.000000, 0.000000, 1.196085;;,
      23;3; 0.000000, 0.000000, 0.910973;;,
      24;3; 0.000000, 0.000000, 0.648610;;,
      25;3; 0.000000, 0.000000, 0.421452;;,
      26;3; 0.000000, 0.000000, 0.238681;;,
      27;3; 0.000000, 0.000000, 0.106065;;,
      28;3; 0.000000, 0.000000, 0.026364;;,
      29;3; 0.000000, 0.000000, 0.000000;;,
      30;3; 0.000000, 0.000000, 0.000000;;,
      31;3; 0.000000, 0.000000, 0.000000;;,
      32;3; 0.000000, 0.000000, 0.000000;;,
      33;3; 0.000000, 0.000000, 0.000000;;,
      34;3; 0.000000, 0.000000, 0.000000;;,
      35;3; 0.000000, 0.000000, 0.000000;;,
      36;3; 0.000000, 0.000000, 0.000000;;,
      37;3; 0.000000, 0.000000, 0.000000;;,
      38;3; 0.000000, 0.000000, 0.000000;;,
      39;3; 0.000000, 0.000000, 0.000000;;,
      40;3; 0.000000, 0.000000, 0.000000;;,
      41;3; 0.000000, 0.000000, 0.000000;;,
      42;3; 0.000000, 0.000000, 0.000000;;,
      43;3; 0.000000, 0.000000, 0.000000;;,
      44;3; 0.000000, 0.000000, 0.000000;;,
      45;3; 0.000000, 0.000000, 0.000000;;,
      46;3; 0.000000, 0.000000, 0.000000;;,
      47;3; 0.000000, 0.000000, 0.000000;;,
      48;3; 0.000000, 0.000000, 0.000000;;,
      49;3; 0.000000, 0.000000, 0.000000;;,
      50;3; 0.000000, 0.000000, 0.000000;;,
      51;3; 0.000000, 0.000000, 0.000000;;,
      52;3; 0.000000, 0.000000, 0.000000;;,
      53;3; 0.000000, 0.000000, 0.000000;;,
      54;3; 0.000000, 0.000000, 0.000000;;,
      55;3; 0.000000, 0.000000, 0.000000;;,
      56;3; 0.000000, 0.000000, 0.000000;;,
      57;3; 0.000000, 0.000000, 0.000000;;,
      58;3; 0.000000, 0.000000, 0.000000;;,
      59;3; 0.000000, 0.000000, 0.000000;;,
      60;3; 0.000000, 0.000000, 0.000000;;,
      61;3; 0.000000, 0.000000, 0.000000;;,
      62;3; 0.000000, 0.000000, 0.000000;;,
      63;3; 0.000000, 0.000000, 0.000000;;,
      64;3; 0.000000, 0.000000, 0.000000;;,
      65;3; 0.000000, 0.000000, 0.000000;;,
      66;3; 0.000000, 0.000000, 0.000000;;,
      67;3; 0.000000, 0.000000, 0.000000;;,
      68;3; 0.000000, 0.000000, 0.000000;;,
      69;3; 0.000000, 0.000000, 0.000000;;,
      70;3; 0.000000, 0.000000, 0.000000;;,
      71;3; 0.000000, 0.000000, 0.000000;;,
      72;3; 0.000000, 0.000000, 0.000000;;,
      73;3; 0.000000, 0.000000, 0.000000;;,
      74;3; 0.000000, 0.000000, 0.000000;;,
      75;3; 0.000000, 0.000000, 0.000000;;,
      76;3; 0.000000, 0.000000, 0.000000;;,
      77;3; 0.000000, 0.000000, 0.000000;;,
      78;3; 0.000000, 0.000000, 0.000000;;,
      79;3; 0.000000, 0.000000, 0.000000;;,
      80;3; 0.000000, 0.000000, 0.000000;;,
      81;3; 0.000000, 0.000000, 0.000000;;,
      82;3; 0.000000, 0.000000, 0.000000;;,
      83;3; 0.000000, 0.000000, 0.000000;;,
      84;3; 0.000000, 0.000000, 0.000000;;,
      85;3; 0.000000, 0.000000, 0.000000;;,
      86;3; 0.000000, 0.000000, 0.000000;;,
      87;3; 0.000000, 0.000000, 0.000000;;,
      88;3; 0.000000, 0.000000, 0.000000;;,
      89;3; 0.000000, 0.000000, 0.000000;;,
      90;3; 0.000000, 0.000000, 0.000000;;,
      91;3; 0.000000, 0.000000, 0.000000;;,
      92;3; 0.000000, 0.000000, 0.000000;;,
      93;3; 0.000000, 0.000000, 0.000000;;,
      94;3; 0.000000, 0.000000, 0.000000;;,
      95;3; 0.000000, 0.000000, 0.000000;;,
      96;3; 0.000000, 0.000000, 0.000000;;,
      97;3; 0.000000, 0.000000, 0.000000;;,
      98;3; 0.000000, 0.000000, 0.000000;;,
      99;3; 0.000000, 0.000000, 0.000000;;,
      100;3; 0.000000, 0.000000, 0.000000;;,
      101;3; 0.000000, 0.000000, 0.000000;;,
      102;3; 0.000000, 0.000000, 0.000000;;,
      103;3; 0.000000, 0.000000, 0.000000;;,
      104;3; 0.000000, 0.000000, 0.000000;;,
      105;3; 0.000000, 0.000000, 0.000000;;,
      106;3; 0.000000, 0.000000, 0.000000;;,
      107;3; 0.000000, 0.000000, 0.000000;;,
      108;3; 0.000000, 0.000000, 0.000000;;,
      109;3; 0.000000, 0.000000, 0.000000;;,
      110;3; 0.000000, 0.000000, 0.000000;;,
      111;3; 0.000000, 0.000000, 0.000000;;,
      112;3; 0.000000, 0.000000, 0.000000;;,
      113;3; 0.000000, 0.000000, 0.000000;;,
      114;3; 0.000000, 0.000000, 0.000000;;,
      115;3; 0.000000, 0.000000, 0.000000;;,
      116;3; 0.000000, 0.000000, 0.000000;;,
      117;3; 0.000000, 0.000000, 0.000000;;,
      118;3; 0.000000, 0.000000, 0.000000;;,
      119;3; 0.000000, 0.000000, 0.000000;;,
      120;3; 0.000000,-0.066507, 0.000000;;,
      121;3; 0.000000,-0.266667, 0.000000;;,
      122;3; 0.000000,-0.592115, 0.000000;;,
      123;3; 0.000000,-1.017785, 0.000000;;,
      124;3; 0.000000,-1.500000, 0.000000;;,
      125;3; 0.000000,-1.982215, 0.000000;;,
      126;3; 0.000000,-2.407885, 0.000000;;,
      127;3; 0.000000,-2.733333, 0.000000;;,
      128;3; 0.000000,-2.933492, 0.000000;;,
      129;3; 0.000000,-3.000000, 0.000000;;,
      130;3; 0.000000,-2.983467, 0.000000;;,
      131;3; 0.000000,-2.933493, 0.000000;;,
      132;3; 0.000000,-2.849930, 0.000000;;,
      133;3; 0.000000,-2.733333, 0.000000;;,
      134;3; 0.000000,-2.585147, 0.000000;;,
      135;3; 0.000000,-2.407885, 0.000000;;,
      136;3; 0.000000,-2.205261, 0.000000;;,
      137;3; 0.000000,-1.982215, 0.000000;;,
      138;3; 0.000000,-1.744815, 0.000000;;,
      139;3; 0.000000,-1.500000, 0.000000;;,
      140;3; 0.000000,-1.255185, 0.000000;;,
      141;3; 0.000000,-1.017785, 0.000000;;,
      142;3; 0.000000,-0.794739, 0.000000;;,
      143;3; 0.000000,-0.592115, 0.000000;;,
      144;3; 0.000000,-0.414853, 0.000000;;,
      145;3; 0.000000,-0.266667, 0.000000;;,
      146;3; 0.000000,-0.150069, 0.000000;;,
      147;3; 0.000000,-0.066508, 0.000000;;,
      148;3; 0.000000,-0.016533, 0.000000;;,
      149;3; 0.000000, 0.000000, 0.000000;;,
      150;3; 0.000000, 0.000000, 0.000000;;,
      151;3; 0.000000, 0.000000, 0.000000;;,
      152;3; 0.000000, 0.000000, 0.000000;;,
      153;3; 0.000000, 0.000000, 0.000000;;,
      154;3; 0.000000, 0.000000, 0.000000;;,
      155;3; 0.000000, 0.000000, 0.000000;;,
      156;3; 0.000000, 0.000000, 0.000000;;,
      157;3; 0.000000, 0.000000, 0.000000;;,
      158;3; 0.000000, 0.000000, 0.000000;;,
      159;3; 0.000000, 0.000000, 0.000000;;,
      160;3; 0.000000, 0.000000, 0.000000;;,
      161;3; 0.000000, 0.000000, 0.000000;;,
      162;3; 0.000000, 0.000000, 0.000000;;,
      163;3; 0.000000, 0.000000, 0.000000;;,
      164;3; 0.000000, 0.000000, 0.000000;;,
      165;3; 0.000000, 0.000000, 0.000000;;,
      166;3; 0.000000, 0.000000, 0.000000;;,
      167;3; 0.000000, 0.000000, 0.000000;;,
      168;3; 0.000000, 0.000000, 0.000000;;,
      169;3; 0.000000, 0.000000, 0.000000;;,
      170;3; 0.000000, 0.000000, 0.000000;;,
      171;3; 0.000000, 0.000000, 0.000000;;,
      172;3; 0.000000, 0.000000, 0.000000;;,
      173;3; 0.000000, 0.000000, 0.000000;;,
      174;3; 0.000000, 0.000000, 0.000000;;,
      175;3; 0.000000, 0.000000, 0.000000;;,
      176;3; 0.000000, 0.000000, 0.000000;;,
      177;3; 0.000000, 0.000000, 0.000000;;,
      178;3; 0.000000, 0.000000, 0.000000;;,
      179;3; 0.000000, 0.000000, 0.000000;;;
    }
  }
} // End of AnimationSet CubeAction
