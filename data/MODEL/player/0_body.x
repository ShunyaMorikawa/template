xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 42;
 -9.14022;2.05927;2.96984;,
 -7.77514;2.05927;5.64897;,
 -3.35311;17.94072;2.04580;,
 -3.94182;17.94072;1.07554;,
 -5.64897;2.05927;7.77514;,
 -2.43618;17.94072;2.81581;,
 -2.96984;2.05927;9.14022;,
 -1.28077;17.94072;3.31018;,
 0.00000;2.05927;9.61060;,
 0.00000;17.94072;3.48053;,
 2.96984;2.05927;9.14022;,
 1.28077;17.94072;3.31018;,
 5.64897;2.05927;7.77514;,
 2.43618;17.94072;2.81581;,
 7.77514;2.05927;5.64897;,
 3.35311;17.94072;2.04580;,
 9.14022;2.05927;2.96984;,
 3.94182;17.94072;1.07554;,
 9.61060;2.05927;0.00000;,
 4.14467;17.94072;0.00000;,
 9.14022;2.05927;-2.96984;,
 3.94182;17.94072;-1.07554;,
 7.77514;2.05927;-5.64897;,
 3.35311;17.94072;-2.04580;,
 5.64897;2.05927;-7.77514;,
 2.43618;17.94072;-2.81580;,
 2.96984;2.05927;-9.14022;,
 1.28077;17.94072;-3.31018;,
 0.00000;2.05927;-9.61059;,
 0.00000;17.94072;-3.48053;,
 -2.96984;2.05927;-9.14022;,
 -1.28077;17.94072;-3.31018;,
 -5.64897;2.05927;-7.77513;,
 -2.43618;17.94072;-2.81580;,
 -7.77513;2.05927;-5.64897;,
 -3.35311;17.94072;-2.04580;,
 -9.14022;2.05927;-2.96984;,
 -3.94182;17.94072;-1.07554;,
 -9.61059;2.05927;0.00000;,
 -4.14467;17.94072;0.00000;,
 0.00000;2.05927;0.00000;,
 0.00000;17.94072;0.00000;;
 
 60;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,0,3,39;,
 3;1,0,40;,
 3;4,1,40;,
 3;6,4,40;,
 3;8,6,40;,
 3;10,8,40;,
 3;12,10,40;,
 3;14,12,40;,
 3;16,14,40;,
 3;18,16,40;,
 3;20,18,40;,
 3;22,20,40;,
 3;24,22,40;,
 3;26,24,40;,
 3;28,26,40;,
 3;30,28,40;,
 3;32,30,40;,
 3;34,32,40;,
 3;36,34,40;,
 3;38,36,40;,
 3;0,38,40;,
 3;3,2,41;,
 3;2,5,41;,
 3;5,7,41;,
 3;7,9,41;,
 3;9,11,41;,
 3;11,13,41;,
 3;13,15,41;,
 3;15,17,41;,
 3;17,19,41;,
 3;19,21,41;,
 3;21,23,41;,
 3;23,25,41;,
 3;25,27,41;,
 3;27,29,41;,
 3;29,31,41;,
 3;31,33,41;,
 3;33,35,41;,
 3;35,37,41;,
 3;37,39,41;,
 3;39,3,41;;
 
 MeshMaterialList {
  1;
  60;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\texture\\SaberUV.png";
   }
  }
 }
 MeshNormals {
  22;
  -0.889516;0.331525;0.314407;,
  -0.738097;0.340324;0.582573;,
  -0.521350;0.349941;0.778290;,
  -0.268367;0.356868;0.894776;,
  0.000000;0.359265;0.933236;,
  0.268367;0.356868;0.894776;,
  0.521350;0.349941;0.778290;,
  0.738097;0.340324;0.582573;,
  0.889516;0.331526;0.314408;,
  0.944742;0.327814;0.000000;,
  0.889516;0.331526;-0.314408;,
  0.738096;0.340324;-0.582575;,
  0.521350;0.349941;-0.778290;,
  0.268368;0.356868;-0.894776;,
  0.000000;0.359265;-0.933236;,
  -0.268368;0.356868;-0.894776;,
  -0.521351;0.349941;-0.778290;,
  -0.738096;0.340324;-0.582575;,
  -0.889516;0.331525;-0.314407;,
  -0.944743;0.327813;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;;
  60;
  4;0,1,1,0;,
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,0,0,19;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;;
 }
 MeshTextureCoords {
  42;
  0.415948;0.621716;,
  0.386015;0.621716;,
  0.289052;0.273478;,
  0.301961;0.273478;,
  0.339394;0.621716;,
  0.268946;0.273478;,
  0.280648;0.621716;,
  0.243611;0.273478;,
  0.215528;0.621716;,
  0.215528;0.273478;,
  0.150407;0.621716;,
  0.187444;0.273478;,
  0.091661;0.621716;,
  0.162109;0.273478;,
  0.045040;0.621716;,
  0.142003;0.273478;,
  0.015107;0.621716;,
  0.129094;0.273478;,
  0.004793;0.621716;,
  0.124646;0.273478;,
  0.015107;0.621716;,
  0.129094;0.273478;,
  0.045040;0.621716;,
  0.142003;0.273478;,
  0.091661;0.621716;,
  0.162109;0.273478;,
  0.150407;0.621716;,
  0.187444;0.273478;,
  0.215528;0.621716;,
  0.215528;0.273478;,
  0.280648;0.621716;,
  0.243611;0.273478;,
  0.339394;0.621716;,
  0.268946;0.273478;,
  0.386015;0.621716;,
  0.289052;0.273478;,
  0.415948;0.621716;,
  0.301961;0.273478;,
  0.426262;0.621716;,
  0.306409;0.273478;,
  0.215528;0.621716;,
  0.215528;0.273478;;
 }
}