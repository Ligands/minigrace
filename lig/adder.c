#include <gracelib.h>
#include <stdlib.h>
#ifndef __CYGWIN__
#pragma weak main
#endif
static char compilerRevision[] = "a6a8af007b1e2c10caf60ddcfdcc155e846f9f82";
static Object undefined;
extern Object none;
extern Object _prelude;
extern Object String;
extern Object Number;
extern Object Boolean;
extern Object Dynamic;
extern Object Block;
extern Object None;
extern Object Type;
extern Object sourceObject;
static Object type_String;
static Object type_Number;
static Object type_Boolean;
static Object type_Block;
static Object type_None;
static Object type_Void;
static Object argv;
static Object emptyclosure;
static Object prelude;
static const char modulename[] = "lig/adder";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "import \"sys\" as sys",
  "method inline{}",
  "//completely inline adder",
  "method add128i(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64, x65, x66, x67, x68, x69, x70, x71, x72, x73, x74, x75, x76, x77, x78, x79, x80, x81, x82, x83, x84, x85, x86, x87, x88, x89, x90, x91, x92, x93, x94, x95, x96, x97, x98, x99, x100, x101, x102, x103, x104, x105, x106, x107, x108, x109, x110, x111, x112, x113, x114, x115, x116, x117, x118, x119, x120, x121, x122, x123, x124, x125, x126, x127, x128) is inline{",
  "        return x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20 + x21 + x22 + x23 + x24 + x25 + x26 + x27 + x28 + x29 + x30 + x31 + x32 + x33 + x34 + x35 + x36 + x37 + x38 + x39 + x40 + x41 + x42 + x43 + x44 + x45 + x46 + x47 + x48 + x49 + x50 + x51 + x52 + x53 + x54 + x55 + x56 + x57 + x58 + x59 + x60 + x61 + x62 + x63 + x64 + x65 + x66 + x67 + x68 + x69 + x70 + x71 + x72 + x73 + x74 + x75 + x76 + x77 + x78 + x79 + x80 + x81 + x82 + x83 + x84 + x85 + x86 + x87 + x88 + x89 + x90 + x91 + x92 + x93 + x94 + x95 + x96 + x97 + x98 + x99 + x100 + x101 + x102 + x103 + x104 + x105 + x106 + x107 + x108 + x109 + x110 + x111 + x112 + x113 + x114 + x115 + x116 + x117 + x118 + x119 + x120 + x121 + x122 + x123 + x124 + x125 + x126 + x127 + x128",
  "}",
  "method add128(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64, x65, x66, x67, x68, x69, x70, x71, x72, x73, x74, x75, x76, x77, x78, x79, x80, x81, x82, x83, x84, x85, x86, x87, x88, x89, x90, x91, x92, x93, x94, x95, x96, x97, x98, x99, x100, x101, x102, x103, x104, x105, x106, x107, x108, x109, x110, x111, x112, x113, x114, x115, x116, x117, x118, x119, x120, x121, x122, x123, x124, x125, x126, x127, x128) is inline{",
  "    return add64(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64) + add64(x65, x66, x67, x68, x69, x70, x71, x72, x73, x74, x75, x76, x77, x78, x79, x80, x81, x82, x83, x84, x85, x86, x87, x88, x89, x90, x91, x92, x93, x94, x95, x96, x97, x98, x99, x100, x101, x102, x103, x104, x105, x106, x107, x108, x109, x110, x111, x112, x113, x114, x115, x116, x117, x118, x119, x120, x121, x122, x123, x124, x125, x126, x127, x128)",
  "}",
  "method add64(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64) is inline{",
  "    return add32(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32) + add32(x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64)",
  "}",
  "method add32(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32) is inline{",
  "    return add16(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16) + add16(x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32)",
  "}",
  "method add16(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16) is inline{",
  "    return add8(x1, x2, x3, x4, x5, x6, x7, x8) + add8(x9, x10, x11, x12, x13, x14, x15, x16)",
  "}",
  "method add8(x1, x2, x3, x4, x5, x6, x7, x8) is inline{",
  "    return add4(x1, x2, x3, x4) + add4(x5, x6, x7, x8)",
  "}",
  "method add4(x1, x2, x3, x4) is inline{",
  "    return add2(x1, x2) + add2(x3, x4)",
  "}",
  "method add2(x1, x2) is inline{",
  "    return x1 + x2",
  "}",
  "method main(){",
  "  concreteadd",
  "  inlineadd",
  "}",
  "method concreteadd(){",
  "  var avg := 0",
  "  var num := 15",
  "  var time",
  "  var x := 0",
  "  for(1..num) do{n ->",
  "    time := sys.cputime",
  "    for(1..1000) do{i->",
  "      x := add128(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256)",
  "    }",
  "    avg := avg + (sys.cputime - time)",
  "  }",
  "  //print (x)",
  "  print(\"annotated concrete average of {num}: {avg/num}s\")",
  "}",
  "method inlineadd(){",
  "  var avg := 0",
  "  var num := 15",
  "  var time",
  "  var x := 0",
  "  for(1..num) do{n ->",
  "    time := sys.cputime",
  "    for(1..1000) do{z->",
  "      x := add128i(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256)",
  "    }",
  "    avg := avg + (sys.cputime - time)",
  "  }",
  "  //print (x)",
  "  print(\"inline average of {num}: {avg/num}s\")",
  "}",
  "main()",
  NULL
};
static Object strlit481;
static Object strlit484;
static Object strlit492;
static Object strlit537;
static Object strlit540;
static Object strlit548;
Object module_sys;
Object module_sys_init();
Object meth_lig_47_adder_inline0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(1, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "inline");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_adder_add128i1(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(129, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add128i");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 128)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *var_x5 = &(stackframe->slots[4]);
  *var_x5 = args[curarg];
  curarg++;
  Object *var_x6 = &(stackframe->slots[5]);
  *var_x6 = args[curarg];
  curarg++;
  Object *var_x7 = &(stackframe->slots[6]);
  *var_x7 = args[curarg];
  curarg++;
  Object *var_x8 = &(stackframe->slots[7]);
  *var_x8 = args[curarg];
  curarg++;
  Object *var_x9 = &(stackframe->slots[8]);
  *var_x9 = args[curarg];
  curarg++;
  Object *var_x10 = &(stackframe->slots[9]);
  *var_x10 = args[curarg];
  curarg++;
  Object *var_x11 = &(stackframe->slots[10]);
  *var_x11 = args[curarg];
  curarg++;
  Object *var_x12 = &(stackframe->slots[11]);
  *var_x12 = args[curarg];
  curarg++;
  Object *var_x13 = &(stackframe->slots[12]);
  *var_x13 = args[curarg];
  curarg++;
  Object *var_x14 = &(stackframe->slots[13]);
  *var_x14 = args[curarg];
  curarg++;
  Object *var_x15 = &(stackframe->slots[14]);
  *var_x15 = args[curarg];
  curarg++;
  Object *var_x16 = &(stackframe->slots[15]);
  *var_x16 = args[curarg];
  curarg++;
  Object *var_x17 = &(stackframe->slots[16]);
  *var_x17 = args[curarg];
  curarg++;
  Object *var_x18 = &(stackframe->slots[17]);
  *var_x18 = args[curarg];
  curarg++;
  Object *var_x19 = &(stackframe->slots[18]);
  *var_x19 = args[curarg];
  curarg++;
  Object *var_x20 = &(stackframe->slots[19]);
  *var_x20 = args[curarg];
  curarg++;
  Object *var_x21 = &(stackframe->slots[20]);
  *var_x21 = args[curarg];
  curarg++;
  Object *var_x22 = &(stackframe->slots[21]);
  *var_x22 = args[curarg];
  curarg++;
  Object *var_x23 = &(stackframe->slots[22]);
  *var_x23 = args[curarg];
  curarg++;
  Object *var_x24 = &(stackframe->slots[23]);
  *var_x24 = args[curarg];
  curarg++;
  Object *var_x25 = &(stackframe->slots[24]);
  *var_x25 = args[curarg];
  curarg++;
  Object *var_x26 = &(stackframe->slots[25]);
  *var_x26 = args[curarg];
  curarg++;
  Object *var_x27 = &(stackframe->slots[26]);
  *var_x27 = args[curarg];
  curarg++;
  Object *var_x28 = &(stackframe->slots[27]);
  *var_x28 = args[curarg];
  curarg++;
  Object *var_x29 = &(stackframe->slots[28]);
  *var_x29 = args[curarg];
  curarg++;
  Object *var_x30 = &(stackframe->slots[29]);
  *var_x30 = args[curarg];
  curarg++;
  Object *var_x31 = &(stackframe->slots[30]);
  *var_x31 = args[curarg];
  curarg++;
  Object *var_x32 = &(stackframe->slots[31]);
  *var_x32 = args[curarg];
  curarg++;
  Object *var_x33 = &(stackframe->slots[32]);
  *var_x33 = args[curarg];
  curarg++;
  Object *var_x34 = &(stackframe->slots[33]);
  *var_x34 = args[curarg];
  curarg++;
  Object *var_x35 = &(stackframe->slots[34]);
  *var_x35 = args[curarg];
  curarg++;
  Object *var_x36 = &(stackframe->slots[35]);
  *var_x36 = args[curarg];
  curarg++;
  Object *var_x37 = &(stackframe->slots[36]);
  *var_x37 = args[curarg];
  curarg++;
  Object *var_x38 = &(stackframe->slots[37]);
  *var_x38 = args[curarg];
  curarg++;
  Object *var_x39 = &(stackframe->slots[38]);
  *var_x39 = args[curarg];
  curarg++;
  Object *var_x40 = &(stackframe->slots[39]);
  *var_x40 = args[curarg];
  curarg++;
  Object *var_x41 = &(stackframe->slots[40]);
  *var_x41 = args[curarg];
  curarg++;
  Object *var_x42 = &(stackframe->slots[41]);
  *var_x42 = args[curarg];
  curarg++;
  Object *var_x43 = &(stackframe->slots[42]);
  *var_x43 = args[curarg];
  curarg++;
  Object *var_x44 = &(stackframe->slots[43]);
  *var_x44 = args[curarg];
  curarg++;
  Object *var_x45 = &(stackframe->slots[44]);
  *var_x45 = args[curarg];
  curarg++;
  Object *var_x46 = &(stackframe->slots[45]);
  *var_x46 = args[curarg];
  curarg++;
  Object *var_x47 = &(stackframe->slots[46]);
  *var_x47 = args[curarg];
  curarg++;
  Object *var_x48 = &(stackframe->slots[47]);
  *var_x48 = args[curarg];
  curarg++;
  Object *var_x49 = &(stackframe->slots[48]);
  *var_x49 = args[curarg];
  curarg++;
  Object *var_x50 = &(stackframe->slots[49]);
  *var_x50 = args[curarg];
  curarg++;
  Object *var_x51 = &(stackframe->slots[50]);
  *var_x51 = args[curarg];
  curarg++;
  Object *var_x52 = &(stackframe->slots[51]);
  *var_x52 = args[curarg];
  curarg++;
  Object *var_x53 = &(stackframe->slots[52]);
  *var_x53 = args[curarg];
  curarg++;
  Object *var_x54 = &(stackframe->slots[53]);
  *var_x54 = args[curarg];
  curarg++;
  Object *var_x55 = &(stackframe->slots[54]);
  *var_x55 = args[curarg];
  curarg++;
  Object *var_x56 = &(stackframe->slots[55]);
  *var_x56 = args[curarg];
  curarg++;
  Object *var_x57 = &(stackframe->slots[56]);
  *var_x57 = args[curarg];
  curarg++;
  Object *var_x58 = &(stackframe->slots[57]);
  *var_x58 = args[curarg];
  curarg++;
  Object *var_x59 = &(stackframe->slots[58]);
  *var_x59 = args[curarg];
  curarg++;
  Object *var_x60 = &(stackframe->slots[59]);
  *var_x60 = args[curarg];
  curarg++;
  Object *var_x61 = &(stackframe->slots[60]);
  *var_x61 = args[curarg];
  curarg++;
  Object *var_x62 = &(stackframe->slots[61]);
  *var_x62 = args[curarg];
  curarg++;
  Object *var_x63 = &(stackframe->slots[62]);
  *var_x63 = args[curarg];
  curarg++;
  Object *var_x64 = &(stackframe->slots[63]);
  *var_x64 = args[curarg];
  curarg++;
  Object *var_x65 = &(stackframe->slots[64]);
  *var_x65 = args[curarg];
  curarg++;
  Object *var_x66 = &(stackframe->slots[65]);
  *var_x66 = args[curarg];
  curarg++;
  Object *var_x67 = &(stackframe->slots[66]);
  *var_x67 = args[curarg];
  curarg++;
  Object *var_x68 = &(stackframe->slots[67]);
  *var_x68 = args[curarg];
  curarg++;
  Object *var_x69 = &(stackframe->slots[68]);
  *var_x69 = args[curarg];
  curarg++;
  Object *var_x70 = &(stackframe->slots[69]);
  *var_x70 = args[curarg];
  curarg++;
  Object *var_x71 = &(stackframe->slots[70]);
  *var_x71 = args[curarg];
  curarg++;
  Object *var_x72 = &(stackframe->slots[71]);
  *var_x72 = args[curarg];
  curarg++;
  Object *var_x73 = &(stackframe->slots[72]);
  *var_x73 = args[curarg];
  curarg++;
  Object *var_x74 = &(stackframe->slots[73]);
  *var_x74 = args[curarg];
  curarg++;
  Object *var_x75 = &(stackframe->slots[74]);
  *var_x75 = args[curarg];
  curarg++;
  Object *var_x76 = &(stackframe->slots[75]);
  *var_x76 = args[curarg];
  curarg++;
  Object *var_x77 = &(stackframe->slots[76]);
  *var_x77 = args[curarg];
  curarg++;
  Object *var_x78 = &(stackframe->slots[77]);
  *var_x78 = args[curarg];
  curarg++;
  Object *var_x79 = &(stackframe->slots[78]);
  *var_x79 = args[curarg];
  curarg++;
  Object *var_x80 = &(stackframe->slots[79]);
  *var_x80 = args[curarg];
  curarg++;
  Object *var_x81 = &(stackframe->slots[80]);
  *var_x81 = args[curarg];
  curarg++;
  Object *var_x82 = &(stackframe->slots[81]);
  *var_x82 = args[curarg];
  curarg++;
  Object *var_x83 = &(stackframe->slots[82]);
  *var_x83 = args[curarg];
  curarg++;
  Object *var_x84 = &(stackframe->slots[83]);
  *var_x84 = args[curarg];
  curarg++;
  Object *var_x85 = &(stackframe->slots[84]);
  *var_x85 = args[curarg];
  curarg++;
  Object *var_x86 = &(stackframe->slots[85]);
  *var_x86 = args[curarg];
  curarg++;
  Object *var_x87 = &(stackframe->slots[86]);
  *var_x87 = args[curarg];
  curarg++;
  Object *var_x88 = &(stackframe->slots[87]);
  *var_x88 = args[curarg];
  curarg++;
  Object *var_x89 = &(stackframe->slots[88]);
  *var_x89 = args[curarg];
  curarg++;
  Object *var_x90 = &(stackframe->slots[89]);
  *var_x90 = args[curarg];
  curarg++;
  Object *var_x91 = &(stackframe->slots[90]);
  *var_x91 = args[curarg];
  curarg++;
  Object *var_x92 = &(stackframe->slots[91]);
  *var_x92 = args[curarg];
  curarg++;
  Object *var_x93 = &(stackframe->slots[92]);
  *var_x93 = args[curarg];
  curarg++;
  Object *var_x94 = &(stackframe->slots[93]);
  *var_x94 = args[curarg];
  curarg++;
  Object *var_x95 = &(stackframe->slots[94]);
  *var_x95 = args[curarg];
  curarg++;
  Object *var_x96 = &(stackframe->slots[95]);
  *var_x96 = args[curarg];
  curarg++;
  Object *var_x97 = &(stackframe->slots[96]);
  *var_x97 = args[curarg];
  curarg++;
  Object *var_x98 = &(stackframe->slots[97]);
  *var_x98 = args[curarg];
  curarg++;
  Object *var_x99 = &(stackframe->slots[98]);
  *var_x99 = args[curarg];
  curarg++;
  Object *var_x100 = &(stackframe->slots[99]);
  *var_x100 = args[curarg];
  curarg++;
  Object *var_x101 = &(stackframe->slots[100]);
  *var_x101 = args[curarg];
  curarg++;
  Object *var_x102 = &(stackframe->slots[101]);
  *var_x102 = args[curarg];
  curarg++;
  Object *var_x103 = &(stackframe->slots[102]);
  *var_x103 = args[curarg];
  curarg++;
  Object *var_x104 = &(stackframe->slots[103]);
  *var_x104 = args[curarg];
  curarg++;
  Object *var_x105 = &(stackframe->slots[104]);
  *var_x105 = args[curarg];
  curarg++;
  Object *var_x106 = &(stackframe->slots[105]);
  *var_x106 = args[curarg];
  curarg++;
  Object *var_x107 = &(stackframe->slots[106]);
  *var_x107 = args[curarg];
  curarg++;
  Object *var_x108 = &(stackframe->slots[107]);
  *var_x108 = args[curarg];
  curarg++;
  Object *var_x109 = &(stackframe->slots[108]);
  *var_x109 = args[curarg];
  curarg++;
  Object *var_x110 = &(stackframe->slots[109]);
  *var_x110 = args[curarg];
  curarg++;
  Object *var_x111 = &(stackframe->slots[110]);
  *var_x111 = args[curarg];
  curarg++;
  Object *var_x112 = &(stackframe->slots[111]);
  *var_x112 = args[curarg];
  curarg++;
  Object *var_x113 = &(stackframe->slots[112]);
  *var_x113 = args[curarg];
  curarg++;
  Object *var_x114 = &(stackframe->slots[113]);
  *var_x114 = args[curarg];
  curarg++;
  Object *var_x115 = &(stackframe->slots[114]);
  *var_x115 = args[curarg];
  curarg++;
  Object *var_x116 = &(stackframe->slots[115]);
  *var_x116 = args[curarg];
  curarg++;
  Object *var_x117 = &(stackframe->slots[116]);
  *var_x117 = args[curarg];
  curarg++;
  Object *var_x118 = &(stackframe->slots[117]);
  *var_x118 = args[curarg];
  curarg++;
  Object *var_x119 = &(stackframe->slots[118]);
  *var_x119 = args[curarg];
  curarg++;
  Object *var_x120 = &(stackframe->slots[119]);
  *var_x120 = args[curarg];
  curarg++;
  Object *var_x121 = &(stackframe->slots[120]);
  *var_x121 = args[curarg];
  curarg++;
  Object *var_x122 = &(stackframe->slots[121]);
  *var_x122 = args[curarg];
  curarg++;
  Object *var_x123 = &(stackframe->slots[122]);
  *var_x123 = args[curarg];
  curarg++;
  Object *var_x124 = &(stackframe->slots[123]);
  *var_x124 = args[curarg];
  curarg++;
  Object *var_x125 = &(stackframe->slots[124]);
  *var_x125 = args[curarg];
  curarg++;
  Object *var_x126 = &(stackframe->slots[125]);
  *var_x126 = args[curarg];
  curarg++;
  Object *var_x127 = &(stackframe->slots[126]);
  *var_x127 = args[curarg];
  curarg++;
  Object *var_x128 = &(stackframe->slots[127]);
  *var_x128 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[128]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_x1
  int op_slot_left_128 = gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  int op_slot_right_128 = gc_frame_newslot(*var_x2);
  params[0] = *var_x2;
  partcv[0] = 1;
  Object sum130 = callmethod(*var_x1, "+", 1, partcv, params);
// compilenode returning sum130
  int op_slot_left_127 = gc_frame_newslot(sum130);
// compilenode returning *var_x3
  int op_slot_right_127 = gc_frame_newslot(*var_x3);
  params[0] = *var_x3;
  partcv[0] = 1;
  Object sum132 = callmethod(sum130, "+", 1, partcv, params);
// compilenode returning sum132
  int op_slot_left_126 = gc_frame_newslot(sum132);
// compilenode returning *var_x4
  int op_slot_right_126 = gc_frame_newslot(*var_x4);
  params[0] = *var_x4;
  partcv[0] = 1;
  Object sum134 = callmethod(sum132, "+", 1, partcv, params);
// compilenode returning sum134
  int op_slot_left_125 = gc_frame_newslot(sum134);
// compilenode returning *var_x5
  int op_slot_right_125 = gc_frame_newslot(*var_x5);
  params[0] = *var_x5;
  partcv[0] = 1;
  Object sum136 = callmethod(sum134, "+", 1, partcv, params);
// compilenode returning sum136
  int op_slot_left_124 = gc_frame_newslot(sum136);
// compilenode returning *var_x6
  int op_slot_right_124 = gc_frame_newslot(*var_x6);
  params[0] = *var_x6;
  partcv[0] = 1;
  Object sum138 = callmethod(sum136, "+", 1, partcv, params);
// compilenode returning sum138
  int op_slot_left_123 = gc_frame_newslot(sum138);
// compilenode returning *var_x7
  int op_slot_right_123 = gc_frame_newslot(*var_x7);
  params[0] = *var_x7;
  partcv[0] = 1;
  Object sum140 = callmethod(sum138, "+", 1, partcv, params);
// compilenode returning sum140
  int op_slot_left_122 = gc_frame_newslot(sum140);
// compilenode returning *var_x8
  int op_slot_right_122 = gc_frame_newslot(*var_x8);
  params[0] = *var_x8;
  partcv[0] = 1;
  Object sum142 = callmethod(sum140, "+", 1, partcv, params);
// compilenode returning sum142
  int op_slot_left_121 = gc_frame_newslot(sum142);
// compilenode returning *var_x9
  int op_slot_right_121 = gc_frame_newslot(*var_x9);
  params[0] = *var_x9;
  partcv[0] = 1;
  Object sum144 = callmethod(sum142, "+", 1, partcv, params);
// compilenode returning sum144
  int op_slot_left_120 = gc_frame_newslot(sum144);
// compilenode returning *var_x10
  int op_slot_right_120 = gc_frame_newslot(*var_x10);
  params[0] = *var_x10;
  partcv[0] = 1;
  Object sum146 = callmethod(sum144, "+", 1, partcv, params);
// compilenode returning sum146
  int op_slot_left_119 = gc_frame_newslot(sum146);
// compilenode returning *var_x11
  int op_slot_right_119 = gc_frame_newslot(*var_x11);
  params[0] = *var_x11;
  partcv[0] = 1;
  Object sum148 = callmethod(sum146, "+", 1, partcv, params);
// compilenode returning sum148
  int op_slot_left_118 = gc_frame_newslot(sum148);
// compilenode returning *var_x12
  int op_slot_right_118 = gc_frame_newslot(*var_x12);
  params[0] = *var_x12;
  partcv[0] = 1;
  Object sum150 = callmethod(sum148, "+", 1, partcv, params);
// compilenode returning sum150
  int op_slot_left_117 = gc_frame_newslot(sum150);
// compilenode returning *var_x13
  int op_slot_right_117 = gc_frame_newslot(*var_x13);
  params[0] = *var_x13;
  partcv[0] = 1;
  Object sum152 = callmethod(sum150, "+", 1, partcv, params);
// compilenode returning sum152
  int op_slot_left_116 = gc_frame_newslot(sum152);
// compilenode returning *var_x14
  int op_slot_right_116 = gc_frame_newslot(*var_x14);
  params[0] = *var_x14;
  partcv[0] = 1;
  Object sum154 = callmethod(sum152, "+", 1, partcv, params);
// compilenode returning sum154
  int op_slot_left_115 = gc_frame_newslot(sum154);
// compilenode returning *var_x15
  int op_slot_right_115 = gc_frame_newslot(*var_x15);
  params[0] = *var_x15;
  partcv[0] = 1;
  Object sum156 = callmethod(sum154, "+", 1, partcv, params);
// compilenode returning sum156
  int op_slot_left_114 = gc_frame_newslot(sum156);
// compilenode returning *var_x16
  int op_slot_right_114 = gc_frame_newslot(*var_x16);
  params[0] = *var_x16;
  partcv[0] = 1;
  Object sum158 = callmethod(sum156, "+", 1, partcv, params);
// compilenode returning sum158
  int op_slot_left_113 = gc_frame_newslot(sum158);
// compilenode returning *var_x17
  int op_slot_right_113 = gc_frame_newslot(*var_x17);
  params[0] = *var_x17;
  partcv[0] = 1;
  Object sum160 = callmethod(sum158, "+", 1, partcv, params);
// compilenode returning sum160
  int op_slot_left_112 = gc_frame_newslot(sum160);
// compilenode returning *var_x18
  int op_slot_right_112 = gc_frame_newslot(*var_x18);
  params[0] = *var_x18;
  partcv[0] = 1;
  Object sum162 = callmethod(sum160, "+", 1, partcv, params);
// compilenode returning sum162
  int op_slot_left_111 = gc_frame_newslot(sum162);
// compilenode returning *var_x19
  int op_slot_right_111 = gc_frame_newslot(*var_x19);
  params[0] = *var_x19;
  partcv[0] = 1;
  Object sum164 = callmethod(sum162, "+", 1, partcv, params);
// compilenode returning sum164
  int op_slot_left_110 = gc_frame_newslot(sum164);
// compilenode returning *var_x20
  int op_slot_right_110 = gc_frame_newslot(*var_x20);
  params[0] = *var_x20;
  partcv[0] = 1;
  Object sum166 = callmethod(sum164, "+", 1, partcv, params);
// compilenode returning sum166
  int op_slot_left_109 = gc_frame_newslot(sum166);
// compilenode returning *var_x21
  int op_slot_right_109 = gc_frame_newslot(*var_x21);
  params[0] = *var_x21;
  partcv[0] = 1;
  Object sum168 = callmethod(sum166, "+", 1, partcv, params);
// compilenode returning sum168
  int op_slot_left_108 = gc_frame_newslot(sum168);
// compilenode returning *var_x22
  int op_slot_right_108 = gc_frame_newslot(*var_x22);
  params[0] = *var_x22;
  partcv[0] = 1;
  Object sum170 = callmethod(sum168, "+", 1, partcv, params);
// compilenode returning sum170
  int op_slot_left_107 = gc_frame_newslot(sum170);
// compilenode returning *var_x23
  int op_slot_right_107 = gc_frame_newslot(*var_x23);
  params[0] = *var_x23;
  partcv[0] = 1;
  Object sum172 = callmethod(sum170, "+", 1, partcv, params);
// compilenode returning sum172
  int op_slot_left_106 = gc_frame_newslot(sum172);
// compilenode returning *var_x24
  int op_slot_right_106 = gc_frame_newslot(*var_x24);
  params[0] = *var_x24;
  partcv[0] = 1;
  Object sum174 = callmethod(sum172, "+", 1, partcv, params);
// compilenode returning sum174
  int op_slot_left_105 = gc_frame_newslot(sum174);
// compilenode returning *var_x25
  int op_slot_right_105 = gc_frame_newslot(*var_x25);
  params[0] = *var_x25;
  partcv[0] = 1;
  Object sum176 = callmethod(sum174, "+", 1, partcv, params);
// compilenode returning sum176
  int op_slot_left_104 = gc_frame_newslot(sum176);
// compilenode returning *var_x26
  int op_slot_right_104 = gc_frame_newslot(*var_x26);
  params[0] = *var_x26;
  partcv[0] = 1;
  Object sum178 = callmethod(sum176, "+", 1, partcv, params);
// compilenode returning sum178
  int op_slot_left_103 = gc_frame_newslot(sum178);
// compilenode returning *var_x27
  int op_slot_right_103 = gc_frame_newslot(*var_x27);
  params[0] = *var_x27;
  partcv[0] = 1;
  Object sum180 = callmethod(sum178, "+", 1, partcv, params);
// compilenode returning sum180
  int op_slot_left_102 = gc_frame_newslot(sum180);
// compilenode returning *var_x28
  int op_slot_right_102 = gc_frame_newslot(*var_x28);
  params[0] = *var_x28;
  partcv[0] = 1;
  Object sum182 = callmethod(sum180, "+", 1, partcv, params);
// compilenode returning sum182
  int op_slot_left_101 = gc_frame_newslot(sum182);
// compilenode returning *var_x29
  int op_slot_right_101 = gc_frame_newslot(*var_x29);
  params[0] = *var_x29;
  partcv[0] = 1;
  Object sum184 = callmethod(sum182, "+", 1, partcv, params);
// compilenode returning sum184
  int op_slot_left_100 = gc_frame_newslot(sum184);
// compilenode returning *var_x30
  int op_slot_right_100 = gc_frame_newslot(*var_x30);
  params[0] = *var_x30;
  partcv[0] = 1;
  Object sum186 = callmethod(sum184, "+", 1, partcv, params);
// compilenode returning sum186
  int op_slot_left_99 = gc_frame_newslot(sum186);
// compilenode returning *var_x31
  int op_slot_right_99 = gc_frame_newslot(*var_x31);
  params[0] = *var_x31;
  partcv[0] = 1;
  Object sum188 = callmethod(sum186, "+", 1, partcv, params);
// compilenode returning sum188
  int op_slot_left_98 = gc_frame_newslot(sum188);
// compilenode returning *var_x32
  int op_slot_right_98 = gc_frame_newslot(*var_x32);
  params[0] = *var_x32;
  partcv[0] = 1;
  Object sum190 = callmethod(sum188, "+", 1, partcv, params);
// compilenode returning sum190
  int op_slot_left_97 = gc_frame_newslot(sum190);
// compilenode returning *var_x33
  int op_slot_right_97 = gc_frame_newslot(*var_x33);
  params[0] = *var_x33;
  partcv[0] = 1;
  Object sum192 = callmethod(sum190, "+", 1, partcv, params);
// compilenode returning sum192
  int op_slot_left_96 = gc_frame_newslot(sum192);
// compilenode returning *var_x34
  int op_slot_right_96 = gc_frame_newslot(*var_x34);
  params[0] = *var_x34;
  partcv[0] = 1;
  Object sum194 = callmethod(sum192, "+", 1, partcv, params);
// compilenode returning sum194
  int op_slot_left_95 = gc_frame_newslot(sum194);
// compilenode returning *var_x35
  int op_slot_right_95 = gc_frame_newslot(*var_x35);
  params[0] = *var_x35;
  partcv[0] = 1;
  Object sum196 = callmethod(sum194, "+", 1, partcv, params);
// compilenode returning sum196
  int op_slot_left_94 = gc_frame_newslot(sum196);
// compilenode returning *var_x36
  int op_slot_right_94 = gc_frame_newslot(*var_x36);
  params[0] = *var_x36;
  partcv[0] = 1;
  Object sum198 = callmethod(sum196, "+", 1, partcv, params);
// compilenode returning sum198
  int op_slot_left_93 = gc_frame_newslot(sum198);
// compilenode returning *var_x37
  int op_slot_right_93 = gc_frame_newslot(*var_x37);
  params[0] = *var_x37;
  partcv[0] = 1;
  Object sum200 = callmethod(sum198, "+", 1, partcv, params);
// compilenode returning sum200
  int op_slot_left_92 = gc_frame_newslot(sum200);
// compilenode returning *var_x38
  int op_slot_right_92 = gc_frame_newslot(*var_x38);
  params[0] = *var_x38;
  partcv[0] = 1;
  Object sum202 = callmethod(sum200, "+", 1, partcv, params);
// compilenode returning sum202
  int op_slot_left_91 = gc_frame_newslot(sum202);
// compilenode returning *var_x39
  int op_slot_right_91 = gc_frame_newslot(*var_x39);
  params[0] = *var_x39;
  partcv[0] = 1;
  Object sum204 = callmethod(sum202, "+", 1, partcv, params);
// compilenode returning sum204
  int op_slot_left_90 = gc_frame_newslot(sum204);
// compilenode returning *var_x40
  int op_slot_right_90 = gc_frame_newslot(*var_x40);
  params[0] = *var_x40;
  partcv[0] = 1;
  Object sum206 = callmethod(sum204, "+", 1, partcv, params);
// compilenode returning sum206
  int op_slot_left_89 = gc_frame_newslot(sum206);
// compilenode returning *var_x41
  int op_slot_right_89 = gc_frame_newslot(*var_x41);
  params[0] = *var_x41;
  partcv[0] = 1;
  Object sum208 = callmethod(sum206, "+", 1, partcv, params);
// compilenode returning sum208
  int op_slot_left_88 = gc_frame_newslot(sum208);
// compilenode returning *var_x42
  int op_slot_right_88 = gc_frame_newslot(*var_x42);
  params[0] = *var_x42;
  partcv[0] = 1;
  Object sum210 = callmethod(sum208, "+", 1, partcv, params);
// compilenode returning sum210
  int op_slot_left_87 = gc_frame_newslot(sum210);
// compilenode returning *var_x43
  int op_slot_right_87 = gc_frame_newslot(*var_x43);
  params[0] = *var_x43;
  partcv[0] = 1;
  Object sum212 = callmethod(sum210, "+", 1, partcv, params);
// compilenode returning sum212
  int op_slot_left_86 = gc_frame_newslot(sum212);
// compilenode returning *var_x44
  int op_slot_right_86 = gc_frame_newslot(*var_x44);
  params[0] = *var_x44;
  partcv[0] = 1;
  Object sum214 = callmethod(sum212, "+", 1, partcv, params);
// compilenode returning sum214
  int op_slot_left_85 = gc_frame_newslot(sum214);
// compilenode returning *var_x45
  int op_slot_right_85 = gc_frame_newslot(*var_x45);
  params[0] = *var_x45;
  partcv[0] = 1;
  Object sum216 = callmethod(sum214, "+", 1, partcv, params);
// compilenode returning sum216
  int op_slot_left_84 = gc_frame_newslot(sum216);
// compilenode returning *var_x46
  int op_slot_right_84 = gc_frame_newslot(*var_x46);
  params[0] = *var_x46;
  partcv[0] = 1;
  Object sum218 = callmethod(sum216, "+", 1, partcv, params);
// compilenode returning sum218
  int op_slot_left_83 = gc_frame_newslot(sum218);
// compilenode returning *var_x47
  int op_slot_right_83 = gc_frame_newslot(*var_x47);
  params[0] = *var_x47;
  partcv[0] = 1;
  Object sum220 = callmethod(sum218, "+", 1, partcv, params);
// compilenode returning sum220
  int op_slot_left_82 = gc_frame_newslot(sum220);
// compilenode returning *var_x48
  int op_slot_right_82 = gc_frame_newslot(*var_x48);
  params[0] = *var_x48;
  partcv[0] = 1;
  Object sum222 = callmethod(sum220, "+", 1, partcv, params);
// compilenode returning sum222
  int op_slot_left_81 = gc_frame_newslot(sum222);
// compilenode returning *var_x49
  int op_slot_right_81 = gc_frame_newslot(*var_x49);
  params[0] = *var_x49;
  partcv[0] = 1;
  Object sum224 = callmethod(sum222, "+", 1, partcv, params);
// compilenode returning sum224
  int op_slot_left_80 = gc_frame_newslot(sum224);
// compilenode returning *var_x50
  int op_slot_right_80 = gc_frame_newslot(*var_x50);
  params[0] = *var_x50;
  partcv[0] = 1;
  Object sum226 = callmethod(sum224, "+", 1, partcv, params);
// compilenode returning sum226
  int op_slot_left_79 = gc_frame_newslot(sum226);
// compilenode returning *var_x51
  int op_slot_right_79 = gc_frame_newslot(*var_x51);
  params[0] = *var_x51;
  partcv[0] = 1;
  Object sum228 = callmethod(sum226, "+", 1, partcv, params);
// compilenode returning sum228
  int op_slot_left_78 = gc_frame_newslot(sum228);
// compilenode returning *var_x52
  int op_slot_right_78 = gc_frame_newslot(*var_x52);
  params[0] = *var_x52;
  partcv[0] = 1;
  Object sum230 = callmethod(sum228, "+", 1, partcv, params);
// compilenode returning sum230
  int op_slot_left_77 = gc_frame_newslot(sum230);
// compilenode returning *var_x53
  int op_slot_right_77 = gc_frame_newslot(*var_x53);
  params[0] = *var_x53;
  partcv[0] = 1;
  Object sum232 = callmethod(sum230, "+", 1, partcv, params);
// compilenode returning sum232
  int op_slot_left_76 = gc_frame_newslot(sum232);
// compilenode returning *var_x54
  int op_slot_right_76 = gc_frame_newslot(*var_x54);
  params[0] = *var_x54;
  partcv[0] = 1;
  Object sum234 = callmethod(sum232, "+", 1, partcv, params);
// compilenode returning sum234
  int op_slot_left_75 = gc_frame_newslot(sum234);
// compilenode returning *var_x55
  int op_slot_right_75 = gc_frame_newslot(*var_x55);
  params[0] = *var_x55;
  partcv[0] = 1;
  Object sum236 = callmethod(sum234, "+", 1, partcv, params);
// compilenode returning sum236
  int op_slot_left_74 = gc_frame_newslot(sum236);
// compilenode returning *var_x56
  int op_slot_right_74 = gc_frame_newslot(*var_x56);
  params[0] = *var_x56;
  partcv[0] = 1;
  Object sum238 = callmethod(sum236, "+", 1, partcv, params);
// compilenode returning sum238
  int op_slot_left_73 = gc_frame_newslot(sum238);
// compilenode returning *var_x57
  int op_slot_right_73 = gc_frame_newslot(*var_x57);
  params[0] = *var_x57;
  partcv[0] = 1;
  Object sum240 = callmethod(sum238, "+", 1, partcv, params);
// compilenode returning sum240
  int op_slot_left_72 = gc_frame_newslot(sum240);
// compilenode returning *var_x58
  int op_slot_right_72 = gc_frame_newslot(*var_x58);
  params[0] = *var_x58;
  partcv[0] = 1;
  Object sum242 = callmethod(sum240, "+", 1, partcv, params);
// compilenode returning sum242
  int op_slot_left_71 = gc_frame_newslot(sum242);
// compilenode returning *var_x59
  int op_slot_right_71 = gc_frame_newslot(*var_x59);
  params[0] = *var_x59;
  partcv[0] = 1;
  Object sum244 = callmethod(sum242, "+", 1, partcv, params);
// compilenode returning sum244
  int op_slot_left_70 = gc_frame_newslot(sum244);
// compilenode returning *var_x60
  int op_slot_right_70 = gc_frame_newslot(*var_x60);
  params[0] = *var_x60;
  partcv[0] = 1;
  Object sum246 = callmethod(sum244, "+", 1, partcv, params);
// compilenode returning sum246
  int op_slot_left_69 = gc_frame_newslot(sum246);
// compilenode returning *var_x61
  int op_slot_right_69 = gc_frame_newslot(*var_x61);
  params[0] = *var_x61;
  partcv[0] = 1;
  Object sum248 = callmethod(sum246, "+", 1, partcv, params);
// compilenode returning sum248
  int op_slot_left_68 = gc_frame_newslot(sum248);
// compilenode returning *var_x62
  int op_slot_right_68 = gc_frame_newslot(*var_x62);
  params[0] = *var_x62;
  partcv[0] = 1;
  Object sum250 = callmethod(sum248, "+", 1, partcv, params);
// compilenode returning sum250
  int op_slot_left_67 = gc_frame_newslot(sum250);
// compilenode returning *var_x63
  int op_slot_right_67 = gc_frame_newslot(*var_x63);
  params[0] = *var_x63;
  partcv[0] = 1;
  Object sum252 = callmethod(sum250, "+", 1, partcv, params);
// compilenode returning sum252
  int op_slot_left_66 = gc_frame_newslot(sum252);
// compilenode returning *var_x64
  int op_slot_right_66 = gc_frame_newslot(*var_x64);
  params[0] = *var_x64;
  partcv[0] = 1;
  Object sum254 = callmethod(sum252, "+", 1, partcv, params);
// compilenode returning sum254
  int op_slot_left_65 = gc_frame_newslot(sum254);
// compilenode returning *var_x65
  int op_slot_right_65 = gc_frame_newslot(*var_x65);
  params[0] = *var_x65;
  partcv[0] = 1;
  Object sum256 = callmethod(sum254, "+", 1, partcv, params);
// compilenode returning sum256
  int op_slot_left_64 = gc_frame_newslot(sum256);
// compilenode returning *var_x66
  int op_slot_right_64 = gc_frame_newslot(*var_x66);
  params[0] = *var_x66;
  partcv[0] = 1;
  Object sum258 = callmethod(sum256, "+", 1, partcv, params);
// compilenode returning sum258
  int op_slot_left_63 = gc_frame_newslot(sum258);
// compilenode returning *var_x67
  int op_slot_right_63 = gc_frame_newslot(*var_x67);
  params[0] = *var_x67;
  partcv[0] = 1;
  Object sum260 = callmethod(sum258, "+", 1, partcv, params);
// compilenode returning sum260
  int op_slot_left_62 = gc_frame_newslot(sum260);
// compilenode returning *var_x68
  int op_slot_right_62 = gc_frame_newslot(*var_x68);
  params[0] = *var_x68;
  partcv[0] = 1;
  Object sum262 = callmethod(sum260, "+", 1, partcv, params);
// compilenode returning sum262
  int op_slot_left_61 = gc_frame_newslot(sum262);
// compilenode returning *var_x69
  int op_slot_right_61 = gc_frame_newslot(*var_x69);
  params[0] = *var_x69;
  partcv[0] = 1;
  Object sum264 = callmethod(sum262, "+", 1, partcv, params);
// compilenode returning sum264
  int op_slot_left_60 = gc_frame_newslot(sum264);
// compilenode returning *var_x70
  int op_slot_right_60 = gc_frame_newslot(*var_x70);
  params[0] = *var_x70;
  partcv[0] = 1;
  Object sum266 = callmethod(sum264, "+", 1, partcv, params);
// compilenode returning sum266
  int op_slot_left_59 = gc_frame_newslot(sum266);
// compilenode returning *var_x71
  int op_slot_right_59 = gc_frame_newslot(*var_x71);
  params[0] = *var_x71;
  partcv[0] = 1;
  Object sum268 = callmethod(sum266, "+", 1, partcv, params);
// compilenode returning sum268
  int op_slot_left_58 = gc_frame_newslot(sum268);
// compilenode returning *var_x72
  int op_slot_right_58 = gc_frame_newslot(*var_x72);
  params[0] = *var_x72;
  partcv[0] = 1;
  Object sum270 = callmethod(sum268, "+", 1, partcv, params);
// compilenode returning sum270
  int op_slot_left_57 = gc_frame_newslot(sum270);
// compilenode returning *var_x73
  int op_slot_right_57 = gc_frame_newslot(*var_x73);
  params[0] = *var_x73;
  partcv[0] = 1;
  Object sum272 = callmethod(sum270, "+", 1, partcv, params);
// compilenode returning sum272
  int op_slot_left_56 = gc_frame_newslot(sum272);
// compilenode returning *var_x74
  int op_slot_right_56 = gc_frame_newslot(*var_x74);
  params[0] = *var_x74;
  partcv[0] = 1;
  Object sum274 = callmethod(sum272, "+", 1, partcv, params);
// compilenode returning sum274
  int op_slot_left_55 = gc_frame_newslot(sum274);
// compilenode returning *var_x75
  int op_slot_right_55 = gc_frame_newslot(*var_x75);
  params[0] = *var_x75;
  partcv[0] = 1;
  Object sum276 = callmethod(sum274, "+", 1, partcv, params);
// compilenode returning sum276
  int op_slot_left_54 = gc_frame_newslot(sum276);
// compilenode returning *var_x76
  int op_slot_right_54 = gc_frame_newslot(*var_x76);
  params[0] = *var_x76;
  partcv[0] = 1;
  Object sum278 = callmethod(sum276, "+", 1, partcv, params);
// compilenode returning sum278
  int op_slot_left_53 = gc_frame_newslot(sum278);
// compilenode returning *var_x77
  int op_slot_right_53 = gc_frame_newslot(*var_x77);
  params[0] = *var_x77;
  partcv[0] = 1;
  Object sum280 = callmethod(sum278, "+", 1, partcv, params);
// compilenode returning sum280
  int op_slot_left_52 = gc_frame_newslot(sum280);
// compilenode returning *var_x78
  int op_slot_right_52 = gc_frame_newslot(*var_x78);
  params[0] = *var_x78;
  partcv[0] = 1;
  Object sum282 = callmethod(sum280, "+", 1, partcv, params);
// compilenode returning sum282
  int op_slot_left_51 = gc_frame_newslot(sum282);
// compilenode returning *var_x79
  int op_slot_right_51 = gc_frame_newslot(*var_x79);
  params[0] = *var_x79;
  partcv[0] = 1;
  Object sum284 = callmethod(sum282, "+", 1, partcv, params);
// compilenode returning sum284
  int op_slot_left_50 = gc_frame_newslot(sum284);
// compilenode returning *var_x80
  int op_slot_right_50 = gc_frame_newslot(*var_x80);
  params[0] = *var_x80;
  partcv[0] = 1;
  Object sum286 = callmethod(sum284, "+", 1, partcv, params);
// compilenode returning sum286
  int op_slot_left_49 = gc_frame_newslot(sum286);
// compilenode returning *var_x81
  int op_slot_right_49 = gc_frame_newslot(*var_x81);
  params[0] = *var_x81;
  partcv[0] = 1;
  Object sum288 = callmethod(sum286, "+", 1, partcv, params);
// compilenode returning sum288
  int op_slot_left_48 = gc_frame_newslot(sum288);
// compilenode returning *var_x82
  int op_slot_right_48 = gc_frame_newslot(*var_x82);
  params[0] = *var_x82;
  partcv[0] = 1;
  Object sum290 = callmethod(sum288, "+", 1, partcv, params);
// compilenode returning sum290
  int op_slot_left_47 = gc_frame_newslot(sum290);
// compilenode returning *var_x83
  int op_slot_right_47 = gc_frame_newslot(*var_x83);
  params[0] = *var_x83;
  partcv[0] = 1;
  Object sum292 = callmethod(sum290, "+", 1, partcv, params);
// compilenode returning sum292
  int op_slot_left_46 = gc_frame_newslot(sum292);
// compilenode returning *var_x84
  int op_slot_right_46 = gc_frame_newslot(*var_x84);
  params[0] = *var_x84;
  partcv[0] = 1;
  Object sum294 = callmethod(sum292, "+", 1, partcv, params);
// compilenode returning sum294
  int op_slot_left_45 = gc_frame_newslot(sum294);
// compilenode returning *var_x85
  int op_slot_right_45 = gc_frame_newslot(*var_x85);
  params[0] = *var_x85;
  partcv[0] = 1;
  Object sum296 = callmethod(sum294, "+", 1, partcv, params);
// compilenode returning sum296
  int op_slot_left_44 = gc_frame_newslot(sum296);
// compilenode returning *var_x86
  int op_slot_right_44 = gc_frame_newslot(*var_x86);
  params[0] = *var_x86;
  partcv[0] = 1;
  Object sum298 = callmethod(sum296, "+", 1, partcv, params);
// compilenode returning sum298
  int op_slot_left_43 = gc_frame_newslot(sum298);
// compilenode returning *var_x87
  int op_slot_right_43 = gc_frame_newslot(*var_x87);
  params[0] = *var_x87;
  partcv[0] = 1;
  Object sum300 = callmethod(sum298, "+", 1, partcv, params);
// compilenode returning sum300
  int op_slot_left_42 = gc_frame_newslot(sum300);
// compilenode returning *var_x88
  int op_slot_right_42 = gc_frame_newslot(*var_x88);
  params[0] = *var_x88;
  partcv[0] = 1;
  Object sum302 = callmethod(sum300, "+", 1, partcv, params);
// compilenode returning sum302
  int op_slot_left_41 = gc_frame_newslot(sum302);
// compilenode returning *var_x89
  int op_slot_right_41 = gc_frame_newslot(*var_x89);
  params[0] = *var_x89;
  partcv[0] = 1;
  Object sum304 = callmethod(sum302, "+", 1, partcv, params);
// compilenode returning sum304
  int op_slot_left_40 = gc_frame_newslot(sum304);
// compilenode returning *var_x90
  int op_slot_right_40 = gc_frame_newslot(*var_x90);
  params[0] = *var_x90;
  partcv[0] = 1;
  Object sum306 = callmethod(sum304, "+", 1, partcv, params);
// compilenode returning sum306
  int op_slot_left_39 = gc_frame_newslot(sum306);
// compilenode returning *var_x91
  int op_slot_right_39 = gc_frame_newslot(*var_x91);
  params[0] = *var_x91;
  partcv[0] = 1;
  Object sum308 = callmethod(sum306, "+", 1, partcv, params);
// compilenode returning sum308
  int op_slot_left_38 = gc_frame_newslot(sum308);
// compilenode returning *var_x92
  int op_slot_right_38 = gc_frame_newslot(*var_x92);
  params[0] = *var_x92;
  partcv[0] = 1;
  Object sum310 = callmethod(sum308, "+", 1, partcv, params);
// compilenode returning sum310
  int op_slot_left_37 = gc_frame_newslot(sum310);
// compilenode returning *var_x93
  int op_slot_right_37 = gc_frame_newslot(*var_x93);
  params[0] = *var_x93;
  partcv[0] = 1;
  Object sum312 = callmethod(sum310, "+", 1, partcv, params);
// compilenode returning sum312
  int op_slot_left_36 = gc_frame_newslot(sum312);
// compilenode returning *var_x94
  int op_slot_right_36 = gc_frame_newslot(*var_x94);
  params[0] = *var_x94;
  partcv[0] = 1;
  Object sum314 = callmethod(sum312, "+", 1, partcv, params);
// compilenode returning sum314
  int op_slot_left_35 = gc_frame_newslot(sum314);
// compilenode returning *var_x95
  int op_slot_right_35 = gc_frame_newslot(*var_x95);
  params[0] = *var_x95;
  partcv[0] = 1;
  Object sum316 = callmethod(sum314, "+", 1, partcv, params);
// compilenode returning sum316
  int op_slot_left_34 = gc_frame_newslot(sum316);
// compilenode returning *var_x96
  int op_slot_right_34 = gc_frame_newslot(*var_x96);
  params[0] = *var_x96;
  partcv[0] = 1;
  Object sum318 = callmethod(sum316, "+", 1, partcv, params);
// compilenode returning sum318
  int op_slot_left_33 = gc_frame_newslot(sum318);
// compilenode returning *var_x97
  int op_slot_right_33 = gc_frame_newslot(*var_x97);
  params[0] = *var_x97;
  partcv[0] = 1;
  Object sum320 = callmethod(sum318, "+", 1, partcv, params);
// compilenode returning sum320
  int op_slot_left_32 = gc_frame_newslot(sum320);
// compilenode returning *var_x98
  int op_slot_right_32 = gc_frame_newslot(*var_x98);
  params[0] = *var_x98;
  partcv[0] = 1;
  Object sum322 = callmethod(sum320, "+", 1, partcv, params);
// compilenode returning sum322
  int op_slot_left_31 = gc_frame_newslot(sum322);
// compilenode returning *var_x99
  int op_slot_right_31 = gc_frame_newslot(*var_x99);
  params[0] = *var_x99;
  partcv[0] = 1;
  Object sum324 = callmethod(sum322, "+", 1, partcv, params);
// compilenode returning sum324
  int op_slot_left_30 = gc_frame_newslot(sum324);
// compilenode returning *var_x100
  int op_slot_right_30 = gc_frame_newslot(*var_x100);
  params[0] = *var_x100;
  partcv[0] = 1;
  Object sum326 = callmethod(sum324, "+", 1, partcv, params);
// compilenode returning sum326
  int op_slot_left_29 = gc_frame_newslot(sum326);
// compilenode returning *var_x101
  int op_slot_right_29 = gc_frame_newslot(*var_x101);
  params[0] = *var_x101;
  partcv[0] = 1;
  Object sum328 = callmethod(sum326, "+", 1, partcv, params);
// compilenode returning sum328
  int op_slot_left_28 = gc_frame_newslot(sum328);
// compilenode returning *var_x102
  int op_slot_right_28 = gc_frame_newslot(*var_x102);
  params[0] = *var_x102;
  partcv[0] = 1;
  Object sum330 = callmethod(sum328, "+", 1, partcv, params);
// compilenode returning sum330
  int op_slot_left_27 = gc_frame_newslot(sum330);
// compilenode returning *var_x103
  int op_slot_right_27 = gc_frame_newslot(*var_x103);
  params[0] = *var_x103;
  partcv[0] = 1;
  Object sum332 = callmethod(sum330, "+", 1, partcv, params);
// compilenode returning sum332
  int op_slot_left_26 = gc_frame_newslot(sum332);
// compilenode returning *var_x104
  int op_slot_right_26 = gc_frame_newslot(*var_x104);
  params[0] = *var_x104;
  partcv[0] = 1;
  Object sum334 = callmethod(sum332, "+", 1, partcv, params);
// compilenode returning sum334
  int op_slot_left_25 = gc_frame_newslot(sum334);
// compilenode returning *var_x105
  int op_slot_right_25 = gc_frame_newslot(*var_x105);
  params[0] = *var_x105;
  partcv[0] = 1;
  Object sum336 = callmethod(sum334, "+", 1, partcv, params);
// compilenode returning sum336
  int op_slot_left_24 = gc_frame_newslot(sum336);
// compilenode returning *var_x106
  int op_slot_right_24 = gc_frame_newslot(*var_x106);
  params[0] = *var_x106;
  partcv[0] = 1;
  Object sum338 = callmethod(sum336, "+", 1, partcv, params);
// compilenode returning sum338
  int op_slot_left_23 = gc_frame_newslot(sum338);
// compilenode returning *var_x107
  int op_slot_right_23 = gc_frame_newslot(*var_x107);
  params[0] = *var_x107;
  partcv[0] = 1;
  Object sum340 = callmethod(sum338, "+", 1, partcv, params);
// compilenode returning sum340
  int op_slot_left_22 = gc_frame_newslot(sum340);
// compilenode returning *var_x108
  int op_slot_right_22 = gc_frame_newslot(*var_x108);
  params[0] = *var_x108;
  partcv[0] = 1;
  Object sum342 = callmethod(sum340, "+", 1, partcv, params);
// compilenode returning sum342
  int op_slot_left_21 = gc_frame_newslot(sum342);
// compilenode returning *var_x109
  int op_slot_right_21 = gc_frame_newslot(*var_x109);
  params[0] = *var_x109;
  partcv[0] = 1;
  Object sum344 = callmethod(sum342, "+", 1, partcv, params);
// compilenode returning sum344
  int op_slot_left_20 = gc_frame_newslot(sum344);
// compilenode returning *var_x110
  int op_slot_right_20 = gc_frame_newslot(*var_x110);
  params[0] = *var_x110;
  partcv[0] = 1;
  Object sum346 = callmethod(sum344, "+", 1, partcv, params);
// compilenode returning sum346
  int op_slot_left_19 = gc_frame_newslot(sum346);
// compilenode returning *var_x111
  int op_slot_right_19 = gc_frame_newslot(*var_x111);
  params[0] = *var_x111;
  partcv[0] = 1;
  Object sum348 = callmethod(sum346, "+", 1, partcv, params);
// compilenode returning sum348
  int op_slot_left_18 = gc_frame_newslot(sum348);
// compilenode returning *var_x112
  int op_slot_right_18 = gc_frame_newslot(*var_x112);
  params[0] = *var_x112;
  partcv[0] = 1;
  Object sum350 = callmethod(sum348, "+", 1, partcv, params);
// compilenode returning sum350
  int op_slot_left_17 = gc_frame_newslot(sum350);
// compilenode returning *var_x113
  int op_slot_right_17 = gc_frame_newslot(*var_x113);
  params[0] = *var_x113;
  partcv[0] = 1;
  Object sum352 = callmethod(sum350, "+", 1, partcv, params);
// compilenode returning sum352
  int op_slot_left_16 = gc_frame_newslot(sum352);
// compilenode returning *var_x114
  int op_slot_right_16 = gc_frame_newslot(*var_x114);
  params[0] = *var_x114;
  partcv[0] = 1;
  Object sum354 = callmethod(sum352, "+", 1, partcv, params);
// compilenode returning sum354
  int op_slot_left_15 = gc_frame_newslot(sum354);
// compilenode returning *var_x115
  int op_slot_right_15 = gc_frame_newslot(*var_x115);
  params[0] = *var_x115;
  partcv[0] = 1;
  Object sum356 = callmethod(sum354, "+", 1, partcv, params);
// compilenode returning sum356
  int op_slot_left_14 = gc_frame_newslot(sum356);
// compilenode returning *var_x116
  int op_slot_right_14 = gc_frame_newslot(*var_x116);
  params[0] = *var_x116;
  partcv[0] = 1;
  Object sum358 = callmethod(sum356, "+", 1, partcv, params);
// compilenode returning sum358
  int op_slot_left_13 = gc_frame_newslot(sum358);
// compilenode returning *var_x117
  int op_slot_right_13 = gc_frame_newslot(*var_x117);
  params[0] = *var_x117;
  partcv[0] = 1;
  Object sum360 = callmethod(sum358, "+", 1, partcv, params);
// compilenode returning sum360
  int op_slot_left_12 = gc_frame_newslot(sum360);
// compilenode returning *var_x118
  int op_slot_right_12 = gc_frame_newslot(*var_x118);
  params[0] = *var_x118;
  partcv[0] = 1;
  Object sum362 = callmethod(sum360, "+", 1, partcv, params);
// compilenode returning sum362
  int op_slot_left_11 = gc_frame_newslot(sum362);
// compilenode returning *var_x119
  int op_slot_right_11 = gc_frame_newslot(*var_x119);
  params[0] = *var_x119;
  partcv[0] = 1;
  Object sum364 = callmethod(sum362, "+", 1, partcv, params);
// compilenode returning sum364
  int op_slot_left_10 = gc_frame_newslot(sum364);
// compilenode returning *var_x120
  int op_slot_right_10 = gc_frame_newslot(*var_x120);
  params[0] = *var_x120;
  partcv[0] = 1;
  Object sum366 = callmethod(sum364, "+", 1, partcv, params);
// compilenode returning sum366
  int op_slot_left_9 = gc_frame_newslot(sum366);
// compilenode returning *var_x121
  int op_slot_right_9 = gc_frame_newslot(*var_x121);
  params[0] = *var_x121;
  partcv[0] = 1;
  Object sum368 = callmethod(sum366, "+", 1, partcv, params);
// compilenode returning sum368
  int op_slot_left_8 = gc_frame_newslot(sum368);
// compilenode returning *var_x122
  int op_slot_right_8 = gc_frame_newslot(*var_x122);
  params[0] = *var_x122;
  partcv[0] = 1;
  Object sum370 = callmethod(sum368, "+", 1, partcv, params);
// compilenode returning sum370
  int op_slot_left_7 = gc_frame_newslot(sum370);
// compilenode returning *var_x123
  int op_slot_right_7 = gc_frame_newslot(*var_x123);
  params[0] = *var_x123;
  partcv[0] = 1;
  Object sum372 = callmethod(sum370, "+", 1, partcv, params);
// compilenode returning sum372
  int op_slot_left_6 = gc_frame_newslot(sum372);
// compilenode returning *var_x124
  int op_slot_right_6 = gc_frame_newslot(*var_x124);
  params[0] = *var_x124;
  partcv[0] = 1;
  Object sum374 = callmethod(sum372, "+", 1, partcv, params);
// compilenode returning sum374
  int op_slot_left_5 = gc_frame_newslot(sum374);
// compilenode returning *var_x125
  int op_slot_right_5 = gc_frame_newslot(*var_x125);
  params[0] = *var_x125;
  partcv[0] = 1;
  Object sum376 = callmethod(sum374, "+", 1, partcv, params);
// compilenode returning sum376
  int op_slot_left_4 = gc_frame_newslot(sum376);
// compilenode returning *var_x126
  int op_slot_right_4 = gc_frame_newslot(*var_x126);
  params[0] = *var_x126;
  partcv[0] = 1;
  Object sum378 = callmethod(sum376, "+", 1, partcv, params);
// compilenode returning sum378
  int op_slot_left_3 = gc_frame_newslot(sum378);
// compilenode returning *var_x127
  int op_slot_right_3 = gc_frame_newslot(*var_x127);
  params[0] = *var_x127;
  partcv[0] = 1;
  Object sum380 = callmethod(sum378, "+", 1, partcv, params);
// compilenode returning sum380
  int op_slot_left_2 = gc_frame_newslot(sum380);
// compilenode returning *var_x128
  int op_slot_right_2 = gc_frame_newslot(*var_x128);
  params[0] = *var_x128;
  partcv[0] = 1;
  Object sum382 = callmethod(sum380, "+", 1, partcv, params);
// compilenode returning sum382
  return sum382;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add128383(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(129, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add128");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 128)
    gracedie("insufficient arguments to method");
  Object params[64];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *var_x5 = &(stackframe->slots[4]);
  *var_x5 = args[curarg];
  curarg++;
  Object *var_x6 = &(stackframe->slots[5]);
  *var_x6 = args[curarg];
  curarg++;
  Object *var_x7 = &(stackframe->slots[6]);
  *var_x7 = args[curarg];
  curarg++;
  Object *var_x8 = &(stackframe->slots[7]);
  *var_x8 = args[curarg];
  curarg++;
  Object *var_x9 = &(stackframe->slots[8]);
  *var_x9 = args[curarg];
  curarg++;
  Object *var_x10 = &(stackframe->slots[9]);
  *var_x10 = args[curarg];
  curarg++;
  Object *var_x11 = &(stackframe->slots[10]);
  *var_x11 = args[curarg];
  curarg++;
  Object *var_x12 = &(stackframe->slots[11]);
  *var_x12 = args[curarg];
  curarg++;
  Object *var_x13 = &(stackframe->slots[12]);
  *var_x13 = args[curarg];
  curarg++;
  Object *var_x14 = &(stackframe->slots[13]);
  *var_x14 = args[curarg];
  curarg++;
  Object *var_x15 = &(stackframe->slots[14]);
  *var_x15 = args[curarg];
  curarg++;
  Object *var_x16 = &(stackframe->slots[15]);
  *var_x16 = args[curarg];
  curarg++;
  Object *var_x17 = &(stackframe->slots[16]);
  *var_x17 = args[curarg];
  curarg++;
  Object *var_x18 = &(stackframe->slots[17]);
  *var_x18 = args[curarg];
  curarg++;
  Object *var_x19 = &(stackframe->slots[18]);
  *var_x19 = args[curarg];
  curarg++;
  Object *var_x20 = &(stackframe->slots[19]);
  *var_x20 = args[curarg];
  curarg++;
  Object *var_x21 = &(stackframe->slots[20]);
  *var_x21 = args[curarg];
  curarg++;
  Object *var_x22 = &(stackframe->slots[21]);
  *var_x22 = args[curarg];
  curarg++;
  Object *var_x23 = &(stackframe->slots[22]);
  *var_x23 = args[curarg];
  curarg++;
  Object *var_x24 = &(stackframe->slots[23]);
  *var_x24 = args[curarg];
  curarg++;
  Object *var_x25 = &(stackframe->slots[24]);
  *var_x25 = args[curarg];
  curarg++;
  Object *var_x26 = &(stackframe->slots[25]);
  *var_x26 = args[curarg];
  curarg++;
  Object *var_x27 = &(stackframe->slots[26]);
  *var_x27 = args[curarg];
  curarg++;
  Object *var_x28 = &(stackframe->slots[27]);
  *var_x28 = args[curarg];
  curarg++;
  Object *var_x29 = &(stackframe->slots[28]);
  *var_x29 = args[curarg];
  curarg++;
  Object *var_x30 = &(stackframe->slots[29]);
  *var_x30 = args[curarg];
  curarg++;
  Object *var_x31 = &(stackframe->slots[30]);
  *var_x31 = args[curarg];
  curarg++;
  Object *var_x32 = &(stackframe->slots[31]);
  *var_x32 = args[curarg];
  curarg++;
  Object *var_x33 = &(stackframe->slots[32]);
  *var_x33 = args[curarg];
  curarg++;
  Object *var_x34 = &(stackframe->slots[33]);
  *var_x34 = args[curarg];
  curarg++;
  Object *var_x35 = &(stackframe->slots[34]);
  *var_x35 = args[curarg];
  curarg++;
  Object *var_x36 = &(stackframe->slots[35]);
  *var_x36 = args[curarg];
  curarg++;
  Object *var_x37 = &(stackframe->slots[36]);
  *var_x37 = args[curarg];
  curarg++;
  Object *var_x38 = &(stackframe->slots[37]);
  *var_x38 = args[curarg];
  curarg++;
  Object *var_x39 = &(stackframe->slots[38]);
  *var_x39 = args[curarg];
  curarg++;
  Object *var_x40 = &(stackframe->slots[39]);
  *var_x40 = args[curarg];
  curarg++;
  Object *var_x41 = &(stackframe->slots[40]);
  *var_x41 = args[curarg];
  curarg++;
  Object *var_x42 = &(stackframe->slots[41]);
  *var_x42 = args[curarg];
  curarg++;
  Object *var_x43 = &(stackframe->slots[42]);
  *var_x43 = args[curarg];
  curarg++;
  Object *var_x44 = &(stackframe->slots[43]);
  *var_x44 = args[curarg];
  curarg++;
  Object *var_x45 = &(stackframe->slots[44]);
  *var_x45 = args[curarg];
  curarg++;
  Object *var_x46 = &(stackframe->slots[45]);
  *var_x46 = args[curarg];
  curarg++;
  Object *var_x47 = &(stackframe->slots[46]);
  *var_x47 = args[curarg];
  curarg++;
  Object *var_x48 = &(stackframe->slots[47]);
  *var_x48 = args[curarg];
  curarg++;
  Object *var_x49 = &(stackframe->slots[48]);
  *var_x49 = args[curarg];
  curarg++;
  Object *var_x50 = &(stackframe->slots[49]);
  *var_x50 = args[curarg];
  curarg++;
  Object *var_x51 = &(stackframe->slots[50]);
  *var_x51 = args[curarg];
  curarg++;
  Object *var_x52 = &(stackframe->slots[51]);
  *var_x52 = args[curarg];
  curarg++;
  Object *var_x53 = &(stackframe->slots[52]);
  *var_x53 = args[curarg];
  curarg++;
  Object *var_x54 = &(stackframe->slots[53]);
  *var_x54 = args[curarg];
  curarg++;
  Object *var_x55 = &(stackframe->slots[54]);
  *var_x55 = args[curarg];
  curarg++;
  Object *var_x56 = &(stackframe->slots[55]);
  *var_x56 = args[curarg];
  curarg++;
  Object *var_x57 = &(stackframe->slots[56]);
  *var_x57 = args[curarg];
  curarg++;
  Object *var_x58 = &(stackframe->slots[57]);
  *var_x58 = args[curarg];
  curarg++;
  Object *var_x59 = &(stackframe->slots[58]);
  *var_x59 = args[curarg];
  curarg++;
  Object *var_x60 = &(stackframe->slots[59]);
  *var_x60 = args[curarg];
  curarg++;
  Object *var_x61 = &(stackframe->slots[60]);
  *var_x61 = args[curarg];
  curarg++;
  Object *var_x62 = &(stackframe->slots[61]);
  *var_x62 = args[curarg];
  curarg++;
  Object *var_x63 = &(stackframe->slots[62]);
  *var_x63 = args[curarg];
  curarg++;
  Object *var_x64 = &(stackframe->slots[63]);
  *var_x64 = args[curarg];
  curarg++;
  Object *var_x65 = &(stackframe->slots[64]);
  *var_x65 = args[curarg];
  curarg++;
  Object *var_x66 = &(stackframe->slots[65]);
  *var_x66 = args[curarg];
  curarg++;
  Object *var_x67 = &(stackframe->slots[66]);
  *var_x67 = args[curarg];
  curarg++;
  Object *var_x68 = &(stackframe->slots[67]);
  *var_x68 = args[curarg];
  curarg++;
  Object *var_x69 = &(stackframe->slots[68]);
  *var_x69 = args[curarg];
  curarg++;
  Object *var_x70 = &(stackframe->slots[69]);
  *var_x70 = args[curarg];
  curarg++;
  Object *var_x71 = &(stackframe->slots[70]);
  *var_x71 = args[curarg];
  curarg++;
  Object *var_x72 = &(stackframe->slots[71]);
  *var_x72 = args[curarg];
  curarg++;
  Object *var_x73 = &(stackframe->slots[72]);
  *var_x73 = args[curarg];
  curarg++;
  Object *var_x74 = &(stackframe->slots[73]);
  *var_x74 = args[curarg];
  curarg++;
  Object *var_x75 = &(stackframe->slots[74]);
  *var_x75 = args[curarg];
  curarg++;
  Object *var_x76 = &(stackframe->slots[75]);
  *var_x76 = args[curarg];
  curarg++;
  Object *var_x77 = &(stackframe->slots[76]);
  *var_x77 = args[curarg];
  curarg++;
  Object *var_x78 = &(stackframe->slots[77]);
  *var_x78 = args[curarg];
  curarg++;
  Object *var_x79 = &(stackframe->slots[78]);
  *var_x79 = args[curarg];
  curarg++;
  Object *var_x80 = &(stackframe->slots[79]);
  *var_x80 = args[curarg];
  curarg++;
  Object *var_x81 = &(stackframe->slots[80]);
  *var_x81 = args[curarg];
  curarg++;
  Object *var_x82 = &(stackframe->slots[81]);
  *var_x82 = args[curarg];
  curarg++;
  Object *var_x83 = &(stackframe->slots[82]);
  *var_x83 = args[curarg];
  curarg++;
  Object *var_x84 = &(stackframe->slots[83]);
  *var_x84 = args[curarg];
  curarg++;
  Object *var_x85 = &(stackframe->slots[84]);
  *var_x85 = args[curarg];
  curarg++;
  Object *var_x86 = &(stackframe->slots[85]);
  *var_x86 = args[curarg];
  curarg++;
  Object *var_x87 = &(stackframe->slots[86]);
  *var_x87 = args[curarg];
  curarg++;
  Object *var_x88 = &(stackframe->slots[87]);
  *var_x88 = args[curarg];
  curarg++;
  Object *var_x89 = &(stackframe->slots[88]);
  *var_x89 = args[curarg];
  curarg++;
  Object *var_x90 = &(stackframe->slots[89]);
  *var_x90 = args[curarg];
  curarg++;
  Object *var_x91 = &(stackframe->slots[90]);
  *var_x91 = args[curarg];
  curarg++;
  Object *var_x92 = &(stackframe->slots[91]);
  *var_x92 = args[curarg];
  curarg++;
  Object *var_x93 = &(stackframe->slots[92]);
  *var_x93 = args[curarg];
  curarg++;
  Object *var_x94 = &(stackframe->slots[93]);
  *var_x94 = args[curarg];
  curarg++;
  Object *var_x95 = &(stackframe->slots[94]);
  *var_x95 = args[curarg];
  curarg++;
  Object *var_x96 = &(stackframe->slots[95]);
  *var_x96 = args[curarg];
  curarg++;
  Object *var_x97 = &(stackframe->slots[96]);
  *var_x97 = args[curarg];
  curarg++;
  Object *var_x98 = &(stackframe->slots[97]);
  *var_x98 = args[curarg];
  curarg++;
  Object *var_x99 = &(stackframe->slots[98]);
  *var_x99 = args[curarg];
  curarg++;
  Object *var_x100 = &(stackframe->slots[99]);
  *var_x100 = args[curarg];
  curarg++;
  Object *var_x101 = &(stackframe->slots[100]);
  *var_x101 = args[curarg];
  curarg++;
  Object *var_x102 = &(stackframe->slots[101]);
  *var_x102 = args[curarg];
  curarg++;
  Object *var_x103 = &(stackframe->slots[102]);
  *var_x103 = args[curarg];
  curarg++;
  Object *var_x104 = &(stackframe->slots[103]);
  *var_x104 = args[curarg];
  curarg++;
  Object *var_x105 = &(stackframe->slots[104]);
  *var_x105 = args[curarg];
  curarg++;
  Object *var_x106 = &(stackframe->slots[105]);
  *var_x106 = args[curarg];
  curarg++;
  Object *var_x107 = &(stackframe->slots[106]);
  *var_x107 = args[curarg];
  curarg++;
  Object *var_x108 = &(stackframe->slots[107]);
  *var_x108 = args[curarg];
  curarg++;
  Object *var_x109 = &(stackframe->slots[108]);
  *var_x109 = args[curarg];
  curarg++;
  Object *var_x110 = &(stackframe->slots[109]);
  *var_x110 = args[curarg];
  curarg++;
  Object *var_x111 = &(stackframe->slots[110]);
  *var_x111 = args[curarg];
  curarg++;
  Object *var_x112 = &(stackframe->slots[111]);
  *var_x112 = args[curarg];
  curarg++;
  Object *var_x113 = &(stackframe->slots[112]);
  *var_x113 = args[curarg];
  curarg++;
  Object *var_x114 = &(stackframe->slots[113]);
  *var_x114 = args[curarg];
  curarg++;
  Object *var_x115 = &(stackframe->slots[114]);
  *var_x115 = args[curarg];
  curarg++;
  Object *var_x116 = &(stackframe->slots[115]);
  *var_x116 = args[curarg];
  curarg++;
  Object *var_x117 = &(stackframe->slots[116]);
  *var_x117 = args[curarg];
  curarg++;
  Object *var_x118 = &(stackframe->slots[117]);
  *var_x118 = args[curarg];
  curarg++;
  Object *var_x119 = &(stackframe->slots[118]);
  *var_x119 = args[curarg];
  curarg++;
  Object *var_x120 = &(stackframe->slots[119]);
  *var_x120 = args[curarg];
  curarg++;
  Object *var_x121 = &(stackframe->slots[120]);
  *var_x121 = args[curarg];
  curarg++;
  Object *var_x122 = &(stackframe->slots[121]);
  *var_x122 = args[curarg];
  curarg++;
  Object *var_x123 = &(stackframe->slots[122]);
  *var_x123 = args[curarg];
  curarg++;
  Object *var_x124 = &(stackframe->slots[123]);
  *var_x124 = args[curarg];
  curarg++;
  Object *var_x125 = &(stackframe->slots[124]);
  *var_x125 = args[curarg];
  curarg++;
  Object *var_x126 = &(stackframe->slots[125]);
  *var_x126 = args[curarg];
  curarg++;
  Object *var_x127 = &(stackframe->slots[126]);
  *var_x127 = args[curarg];
  curarg++;
  Object *var_x128 = &(stackframe->slots[127]);
  *var_x128 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[128]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe385 = gc_frame_new();
// compilenode returning *var_x1
  gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  gc_frame_newslot(*var_x2);
// compilenode returning *var_x3
  gc_frame_newslot(*var_x3);
// compilenode returning *var_x4
  gc_frame_newslot(*var_x4);
// compilenode returning *var_x5
  gc_frame_newslot(*var_x5);
// compilenode returning *var_x6
  gc_frame_newslot(*var_x6);
// compilenode returning *var_x7
  gc_frame_newslot(*var_x7);
// compilenode returning *var_x8
  gc_frame_newslot(*var_x8);
// compilenode returning *var_x9
  gc_frame_newslot(*var_x9);
// compilenode returning *var_x10
  gc_frame_newslot(*var_x10);
// compilenode returning *var_x11
  gc_frame_newslot(*var_x11);
// compilenode returning *var_x12
  gc_frame_newslot(*var_x12);
// compilenode returning *var_x13
  gc_frame_newslot(*var_x13);
// compilenode returning *var_x14
  gc_frame_newslot(*var_x14);
// compilenode returning *var_x15
  gc_frame_newslot(*var_x15);
// compilenode returning *var_x16
  gc_frame_newslot(*var_x16);
// compilenode returning *var_x17
  gc_frame_newslot(*var_x17);
// compilenode returning *var_x18
  gc_frame_newslot(*var_x18);
// compilenode returning *var_x19
  gc_frame_newslot(*var_x19);
// compilenode returning *var_x20
  gc_frame_newslot(*var_x20);
// compilenode returning *var_x21
  gc_frame_newslot(*var_x21);
// compilenode returning *var_x22
  gc_frame_newslot(*var_x22);
// compilenode returning *var_x23
  gc_frame_newslot(*var_x23);
// compilenode returning *var_x24
  gc_frame_newslot(*var_x24);
// compilenode returning *var_x25
  gc_frame_newslot(*var_x25);
// compilenode returning *var_x26
  gc_frame_newslot(*var_x26);
// compilenode returning *var_x27
  gc_frame_newslot(*var_x27);
// compilenode returning *var_x28
  gc_frame_newslot(*var_x28);
// compilenode returning *var_x29
  gc_frame_newslot(*var_x29);
// compilenode returning *var_x30
  gc_frame_newslot(*var_x30);
// compilenode returning *var_x31
  gc_frame_newslot(*var_x31);
// compilenode returning *var_x32
  gc_frame_newslot(*var_x32);
// compilenode returning *var_x33
  gc_frame_newslot(*var_x33);
// compilenode returning *var_x34
  gc_frame_newslot(*var_x34);
// compilenode returning *var_x35
  gc_frame_newslot(*var_x35);
// compilenode returning *var_x36
  gc_frame_newslot(*var_x36);
// compilenode returning *var_x37
  gc_frame_newslot(*var_x37);
// compilenode returning *var_x38
  gc_frame_newslot(*var_x38);
// compilenode returning *var_x39
  gc_frame_newslot(*var_x39);
// compilenode returning *var_x40
  gc_frame_newslot(*var_x40);
// compilenode returning *var_x41
  gc_frame_newslot(*var_x41);
// compilenode returning *var_x42
  gc_frame_newslot(*var_x42);
// compilenode returning *var_x43
  gc_frame_newslot(*var_x43);
// compilenode returning *var_x44
  gc_frame_newslot(*var_x44);
// compilenode returning *var_x45
  gc_frame_newslot(*var_x45);
// compilenode returning *var_x46
  gc_frame_newslot(*var_x46);
// compilenode returning *var_x47
  gc_frame_newslot(*var_x47);
// compilenode returning *var_x48
  gc_frame_newslot(*var_x48);
// compilenode returning *var_x49
  gc_frame_newslot(*var_x49);
// compilenode returning *var_x50
  gc_frame_newslot(*var_x50);
// compilenode returning *var_x51
  gc_frame_newslot(*var_x51);
// compilenode returning *var_x52
  gc_frame_newslot(*var_x52);
// compilenode returning *var_x53
  gc_frame_newslot(*var_x53);
// compilenode returning *var_x54
  gc_frame_newslot(*var_x54);
// compilenode returning *var_x55
  gc_frame_newslot(*var_x55);
// compilenode returning *var_x56
  gc_frame_newslot(*var_x56);
// compilenode returning *var_x57
  gc_frame_newslot(*var_x57);
// compilenode returning *var_x58
  gc_frame_newslot(*var_x58);
// compilenode returning *var_x59
  gc_frame_newslot(*var_x59);
// compilenode returning *var_x60
  gc_frame_newslot(*var_x60);
// compilenode returning *var_x61
  gc_frame_newslot(*var_x61);
// compilenode returning *var_x62
  gc_frame_newslot(*var_x62);
// compilenode returning *var_x63
  gc_frame_newslot(*var_x63);
// compilenode returning *var_x64
  gc_frame_newslot(*var_x64);
  params[0] = *var_x1;
  params[1] = *var_x2;
  params[2] = *var_x3;
  params[3] = *var_x4;
  params[4] = *var_x5;
  params[5] = *var_x6;
  params[6] = *var_x7;
  params[7] = *var_x8;
  params[8] = *var_x9;
  params[9] = *var_x10;
  params[10] = *var_x11;
  params[11] = *var_x12;
  params[12] = *var_x13;
  params[13] = *var_x14;
  params[14] = *var_x15;
  params[15] = *var_x16;
  params[16] = *var_x17;
  params[17] = *var_x18;
  params[18] = *var_x19;
  params[19] = *var_x20;
  params[20] = *var_x21;
  params[21] = *var_x22;
  params[22] = *var_x23;
  params[23] = *var_x24;
  params[24] = *var_x25;
  params[25] = *var_x26;
  params[26] = *var_x27;
  params[27] = *var_x28;
  params[28] = *var_x29;
  params[29] = *var_x30;
  params[30] = *var_x31;
  params[31] = *var_x32;
  params[32] = *var_x33;
  params[33] = *var_x34;
  params[34] = *var_x35;
  params[35] = *var_x36;
  params[36] = *var_x37;
  params[37] = *var_x38;
  params[38] = *var_x39;
  params[39] = *var_x40;
  params[40] = *var_x41;
  params[41] = *var_x42;
  params[42] = *var_x43;
  params[43] = *var_x44;
  params[44] = *var_x45;
  params[45] = *var_x46;
  params[46] = *var_x47;
  params[47] = *var_x48;
  params[48] = *var_x49;
  params[49] = *var_x50;
  params[50] = *var_x51;
  params[51] = *var_x52;
  params[52] = *var_x53;
  params[53] = *var_x54;
  params[54] = *var_x55;
  params[55] = *var_x56;
  params[56] = *var_x57;
  params[57] = *var_x58;
  params[58] = *var_x59;
  params[59] = *var_x60;
  params[60] = *var_x61;
  params[61] = *var_x62;
  params[62] = *var_x63;
  params[63] = *var_x64;
  partcv[0] = 64;
  Object call386 = callmethodflags(self, "add64", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe385);
// compilenode returning call386
  int op_slot_left_384 = gc_frame_newslot(call386);
  int callframe387 = gc_frame_new();
// compilenode returning *var_x65
  gc_frame_newslot(*var_x65);
// compilenode returning *var_x66
  gc_frame_newslot(*var_x66);
// compilenode returning *var_x67
  gc_frame_newslot(*var_x67);
// compilenode returning *var_x68
  gc_frame_newslot(*var_x68);
// compilenode returning *var_x69
  gc_frame_newslot(*var_x69);
// compilenode returning *var_x70
  gc_frame_newslot(*var_x70);
// compilenode returning *var_x71
  gc_frame_newslot(*var_x71);
// compilenode returning *var_x72
  gc_frame_newslot(*var_x72);
// compilenode returning *var_x73
  gc_frame_newslot(*var_x73);
// compilenode returning *var_x74
  gc_frame_newslot(*var_x74);
// compilenode returning *var_x75
  gc_frame_newslot(*var_x75);
// compilenode returning *var_x76
  gc_frame_newslot(*var_x76);
// compilenode returning *var_x77
  gc_frame_newslot(*var_x77);
// compilenode returning *var_x78
  gc_frame_newslot(*var_x78);
// compilenode returning *var_x79
  gc_frame_newslot(*var_x79);
// compilenode returning *var_x80
  gc_frame_newslot(*var_x80);
// compilenode returning *var_x81
  gc_frame_newslot(*var_x81);
// compilenode returning *var_x82
  gc_frame_newslot(*var_x82);
// compilenode returning *var_x83
  gc_frame_newslot(*var_x83);
// compilenode returning *var_x84
  gc_frame_newslot(*var_x84);
// compilenode returning *var_x85
  gc_frame_newslot(*var_x85);
// compilenode returning *var_x86
  gc_frame_newslot(*var_x86);
// compilenode returning *var_x87
  gc_frame_newslot(*var_x87);
// compilenode returning *var_x88
  gc_frame_newslot(*var_x88);
// compilenode returning *var_x89
  gc_frame_newslot(*var_x89);
// compilenode returning *var_x90
  gc_frame_newslot(*var_x90);
// compilenode returning *var_x91
  gc_frame_newslot(*var_x91);
// compilenode returning *var_x92
  gc_frame_newslot(*var_x92);
// compilenode returning *var_x93
  gc_frame_newslot(*var_x93);
// compilenode returning *var_x94
  gc_frame_newslot(*var_x94);
// compilenode returning *var_x95
  gc_frame_newslot(*var_x95);
// compilenode returning *var_x96
  gc_frame_newslot(*var_x96);
// compilenode returning *var_x97
  gc_frame_newslot(*var_x97);
// compilenode returning *var_x98
  gc_frame_newslot(*var_x98);
// compilenode returning *var_x99
  gc_frame_newslot(*var_x99);
// compilenode returning *var_x100
  gc_frame_newslot(*var_x100);
// compilenode returning *var_x101
  gc_frame_newslot(*var_x101);
// compilenode returning *var_x102
  gc_frame_newslot(*var_x102);
// compilenode returning *var_x103
  gc_frame_newslot(*var_x103);
// compilenode returning *var_x104
  gc_frame_newslot(*var_x104);
// compilenode returning *var_x105
  gc_frame_newslot(*var_x105);
// compilenode returning *var_x106
  gc_frame_newslot(*var_x106);
// compilenode returning *var_x107
  gc_frame_newslot(*var_x107);
// compilenode returning *var_x108
  gc_frame_newslot(*var_x108);
// compilenode returning *var_x109
  gc_frame_newslot(*var_x109);
// compilenode returning *var_x110
  gc_frame_newslot(*var_x110);
// compilenode returning *var_x111
  gc_frame_newslot(*var_x111);
// compilenode returning *var_x112
  gc_frame_newslot(*var_x112);
// compilenode returning *var_x113
  gc_frame_newslot(*var_x113);
// compilenode returning *var_x114
  gc_frame_newslot(*var_x114);
// compilenode returning *var_x115
  gc_frame_newslot(*var_x115);
// compilenode returning *var_x116
  gc_frame_newslot(*var_x116);
// compilenode returning *var_x117
  gc_frame_newslot(*var_x117);
// compilenode returning *var_x118
  gc_frame_newslot(*var_x118);
// compilenode returning *var_x119
  gc_frame_newslot(*var_x119);
// compilenode returning *var_x120
  gc_frame_newslot(*var_x120);
// compilenode returning *var_x121
  gc_frame_newslot(*var_x121);
// compilenode returning *var_x122
  gc_frame_newslot(*var_x122);
// compilenode returning *var_x123
  gc_frame_newslot(*var_x123);
// compilenode returning *var_x124
  gc_frame_newslot(*var_x124);
// compilenode returning *var_x125
  gc_frame_newslot(*var_x125);
// compilenode returning *var_x126
  gc_frame_newslot(*var_x126);
// compilenode returning *var_x127
  gc_frame_newslot(*var_x127);
// compilenode returning *var_x128
  gc_frame_newslot(*var_x128);
  params[0] = *var_x65;
  params[1] = *var_x66;
  params[2] = *var_x67;
  params[3] = *var_x68;
  params[4] = *var_x69;
  params[5] = *var_x70;
  params[6] = *var_x71;
  params[7] = *var_x72;
  params[8] = *var_x73;
  params[9] = *var_x74;
  params[10] = *var_x75;
  params[11] = *var_x76;
  params[12] = *var_x77;
  params[13] = *var_x78;
  params[14] = *var_x79;
  params[15] = *var_x80;
  params[16] = *var_x81;
  params[17] = *var_x82;
  params[18] = *var_x83;
  params[19] = *var_x84;
  params[20] = *var_x85;
  params[21] = *var_x86;
  params[22] = *var_x87;
  params[23] = *var_x88;
  params[24] = *var_x89;
  params[25] = *var_x90;
  params[26] = *var_x91;
  params[27] = *var_x92;
  params[28] = *var_x93;
  params[29] = *var_x94;
  params[30] = *var_x95;
  params[31] = *var_x96;
  params[32] = *var_x97;
  params[33] = *var_x98;
  params[34] = *var_x99;
  params[35] = *var_x100;
  params[36] = *var_x101;
  params[37] = *var_x102;
  params[38] = *var_x103;
  params[39] = *var_x104;
  params[40] = *var_x105;
  params[41] = *var_x106;
  params[42] = *var_x107;
  params[43] = *var_x108;
  params[44] = *var_x109;
  params[45] = *var_x110;
  params[46] = *var_x111;
  params[47] = *var_x112;
  params[48] = *var_x113;
  params[49] = *var_x114;
  params[50] = *var_x115;
  params[51] = *var_x116;
  params[52] = *var_x117;
  params[53] = *var_x118;
  params[54] = *var_x119;
  params[55] = *var_x120;
  params[56] = *var_x121;
  params[57] = *var_x122;
  params[58] = *var_x123;
  params[59] = *var_x124;
  params[60] = *var_x125;
  params[61] = *var_x126;
  params[62] = *var_x127;
  params[63] = *var_x128;
  partcv[0] = 64;
  Object call388 = callmethodflags(self, "add64", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe387);
// compilenode returning call388
  int op_slot_right_384 = gc_frame_newslot(call388);
  params[0] = call388;
  partcv[0] = 1;
  Object sum390 = callmethod(call386, "+", 1, partcv, params);
// compilenode returning sum390
  return sum390;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add64391(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(65, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add64");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 64)
    gracedie("insufficient arguments to method");
  Object params[32];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *var_x5 = &(stackframe->slots[4]);
  *var_x5 = args[curarg];
  curarg++;
  Object *var_x6 = &(stackframe->slots[5]);
  *var_x6 = args[curarg];
  curarg++;
  Object *var_x7 = &(stackframe->slots[6]);
  *var_x7 = args[curarg];
  curarg++;
  Object *var_x8 = &(stackframe->slots[7]);
  *var_x8 = args[curarg];
  curarg++;
  Object *var_x9 = &(stackframe->slots[8]);
  *var_x9 = args[curarg];
  curarg++;
  Object *var_x10 = &(stackframe->slots[9]);
  *var_x10 = args[curarg];
  curarg++;
  Object *var_x11 = &(stackframe->slots[10]);
  *var_x11 = args[curarg];
  curarg++;
  Object *var_x12 = &(stackframe->slots[11]);
  *var_x12 = args[curarg];
  curarg++;
  Object *var_x13 = &(stackframe->slots[12]);
  *var_x13 = args[curarg];
  curarg++;
  Object *var_x14 = &(stackframe->slots[13]);
  *var_x14 = args[curarg];
  curarg++;
  Object *var_x15 = &(stackframe->slots[14]);
  *var_x15 = args[curarg];
  curarg++;
  Object *var_x16 = &(stackframe->slots[15]);
  *var_x16 = args[curarg];
  curarg++;
  Object *var_x17 = &(stackframe->slots[16]);
  *var_x17 = args[curarg];
  curarg++;
  Object *var_x18 = &(stackframe->slots[17]);
  *var_x18 = args[curarg];
  curarg++;
  Object *var_x19 = &(stackframe->slots[18]);
  *var_x19 = args[curarg];
  curarg++;
  Object *var_x20 = &(stackframe->slots[19]);
  *var_x20 = args[curarg];
  curarg++;
  Object *var_x21 = &(stackframe->slots[20]);
  *var_x21 = args[curarg];
  curarg++;
  Object *var_x22 = &(stackframe->slots[21]);
  *var_x22 = args[curarg];
  curarg++;
  Object *var_x23 = &(stackframe->slots[22]);
  *var_x23 = args[curarg];
  curarg++;
  Object *var_x24 = &(stackframe->slots[23]);
  *var_x24 = args[curarg];
  curarg++;
  Object *var_x25 = &(stackframe->slots[24]);
  *var_x25 = args[curarg];
  curarg++;
  Object *var_x26 = &(stackframe->slots[25]);
  *var_x26 = args[curarg];
  curarg++;
  Object *var_x27 = &(stackframe->slots[26]);
  *var_x27 = args[curarg];
  curarg++;
  Object *var_x28 = &(stackframe->slots[27]);
  *var_x28 = args[curarg];
  curarg++;
  Object *var_x29 = &(stackframe->slots[28]);
  *var_x29 = args[curarg];
  curarg++;
  Object *var_x30 = &(stackframe->slots[29]);
  *var_x30 = args[curarg];
  curarg++;
  Object *var_x31 = &(stackframe->slots[30]);
  *var_x31 = args[curarg];
  curarg++;
  Object *var_x32 = &(stackframe->slots[31]);
  *var_x32 = args[curarg];
  curarg++;
  Object *var_x33 = &(stackframe->slots[32]);
  *var_x33 = args[curarg];
  curarg++;
  Object *var_x34 = &(stackframe->slots[33]);
  *var_x34 = args[curarg];
  curarg++;
  Object *var_x35 = &(stackframe->slots[34]);
  *var_x35 = args[curarg];
  curarg++;
  Object *var_x36 = &(stackframe->slots[35]);
  *var_x36 = args[curarg];
  curarg++;
  Object *var_x37 = &(stackframe->slots[36]);
  *var_x37 = args[curarg];
  curarg++;
  Object *var_x38 = &(stackframe->slots[37]);
  *var_x38 = args[curarg];
  curarg++;
  Object *var_x39 = &(stackframe->slots[38]);
  *var_x39 = args[curarg];
  curarg++;
  Object *var_x40 = &(stackframe->slots[39]);
  *var_x40 = args[curarg];
  curarg++;
  Object *var_x41 = &(stackframe->slots[40]);
  *var_x41 = args[curarg];
  curarg++;
  Object *var_x42 = &(stackframe->slots[41]);
  *var_x42 = args[curarg];
  curarg++;
  Object *var_x43 = &(stackframe->slots[42]);
  *var_x43 = args[curarg];
  curarg++;
  Object *var_x44 = &(stackframe->slots[43]);
  *var_x44 = args[curarg];
  curarg++;
  Object *var_x45 = &(stackframe->slots[44]);
  *var_x45 = args[curarg];
  curarg++;
  Object *var_x46 = &(stackframe->slots[45]);
  *var_x46 = args[curarg];
  curarg++;
  Object *var_x47 = &(stackframe->slots[46]);
  *var_x47 = args[curarg];
  curarg++;
  Object *var_x48 = &(stackframe->slots[47]);
  *var_x48 = args[curarg];
  curarg++;
  Object *var_x49 = &(stackframe->slots[48]);
  *var_x49 = args[curarg];
  curarg++;
  Object *var_x50 = &(stackframe->slots[49]);
  *var_x50 = args[curarg];
  curarg++;
  Object *var_x51 = &(stackframe->slots[50]);
  *var_x51 = args[curarg];
  curarg++;
  Object *var_x52 = &(stackframe->slots[51]);
  *var_x52 = args[curarg];
  curarg++;
  Object *var_x53 = &(stackframe->slots[52]);
  *var_x53 = args[curarg];
  curarg++;
  Object *var_x54 = &(stackframe->slots[53]);
  *var_x54 = args[curarg];
  curarg++;
  Object *var_x55 = &(stackframe->slots[54]);
  *var_x55 = args[curarg];
  curarg++;
  Object *var_x56 = &(stackframe->slots[55]);
  *var_x56 = args[curarg];
  curarg++;
  Object *var_x57 = &(stackframe->slots[56]);
  *var_x57 = args[curarg];
  curarg++;
  Object *var_x58 = &(stackframe->slots[57]);
  *var_x58 = args[curarg];
  curarg++;
  Object *var_x59 = &(stackframe->slots[58]);
  *var_x59 = args[curarg];
  curarg++;
  Object *var_x60 = &(stackframe->slots[59]);
  *var_x60 = args[curarg];
  curarg++;
  Object *var_x61 = &(stackframe->slots[60]);
  *var_x61 = args[curarg];
  curarg++;
  Object *var_x62 = &(stackframe->slots[61]);
  *var_x62 = args[curarg];
  curarg++;
  Object *var_x63 = &(stackframe->slots[62]);
  *var_x63 = args[curarg];
  curarg++;
  Object *var_x64 = &(stackframe->slots[63]);
  *var_x64 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[64]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe393 = gc_frame_new();
// compilenode returning *var_x1
  gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  gc_frame_newslot(*var_x2);
// compilenode returning *var_x3
  gc_frame_newslot(*var_x3);
// compilenode returning *var_x4
  gc_frame_newslot(*var_x4);
// compilenode returning *var_x5
  gc_frame_newslot(*var_x5);
// compilenode returning *var_x6
  gc_frame_newslot(*var_x6);
// compilenode returning *var_x7
  gc_frame_newslot(*var_x7);
// compilenode returning *var_x8
  gc_frame_newslot(*var_x8);
// compilenode returning *var_x9
  gc_frame_newslot(*var_x9);
// compilenode returning *var_x10
  gc_frame_newslot(*var_x10);
// compilenode returning *var_x11
  gc_frame_newslot(*var_x11);
// compilenode returning *var_x12
  gc_frame_newslot(*var_x12);
// compilenode returning *var_x13
  gc_frame_newslot(*var_x13);
// compilenode returning *var_x14
  gc_frame_newslot(*var_x14);
// compilenode returning *var_x15
  gc_frame_newslot(*var_x15);
// compilenode returning *var_x16
  gc_frame_newslot(*var_x16);
// compilenode returning *var_x17
  gc_frame_newslot(*var_x17);
// compilenode returning *var_x18
  gc_frame_newslot(*var_x18);
// compilenode returning *var_x19
  gc_frame_newslot(*var_x19);
// compilenode returning *var_x20
  gc_frame_newslot(*var_x20);
// compilenode returning *var_x21
  gc_frame_newslot(*var_x21);
// compilenode returning *var_x22
  gc_frame_newslot(*var_x22);
// compilenode returning *var_x23
  gc_frame_newslot(*var_x23);
// compilenode returning *var_x24
  gc_frame_newslot(*var_x24);
// compilenode returning *var_x25
  gc_frame_newslot(*var_x25);
// compilenode returning *var_x26
  gc_frame_newslot(*var_x26);
// compilenode returning *var_x27
  gc_frame_newslot(*var_x27);
// compilenode returning *var_x28
  gc_frame_newslot(*var_x28);
// compilenode returning *var_x29
  gc_frame_newslot(*var_x29);
// compilenode returning *var_x30
  gc_frame_newslot(*var_x30);
// compilenode returning *var_x31
  gc_frame_newslot(*var_x31);
// compilenode returning *var_x32
  gc_frame_newslot(*var_x32);
  params[0] = *var_x1;
  params[1] = *var_x2;
  params[2] = *var_x3;
  params[3] = *var_x4;
  params[4] = *var_x5;
  params[5] = *var_x6;
  params[6] = *var_x7;
  params[7] = *var_x8;
  params[8] = *var_x9;
  params[9] = *var_x10;
  params[10] = *var_x11;
  params[11] = *var_x12;
  params[12] = *var_x13;
  params[13] = *var_x14;
  params[14] = *var_x15;
  params[15] = *var_x16;
  params[16] = *var_x17;
  params[17] = *var_x18;
  params[18] = *var_x19;
  params[19] = *var_x20;
  params[20] = *var_x21;
  params[21] = *var_x22;
  params[22] = *var_x23;
  params[23] = *var_x24;
  params[24] = *var_x25;
  params[25] = *var_x26;
  params[26] = *var_x27;
  params[27] = *var_x28;
  params[28] = *var_x29;
  params[29] = *var_x30;
  params[30] = *var_x31;
  params[31] = *var_x32;
  partcv[0] = 32;
  Object call394 = callmethodflags(self, "add32", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe393);
// compilenode returning call394
  int op_slot_left_392 = gc_frame_newslot(call394);
  int callframe395 = gc_frame_new();
// compilenode returning *var_x33
  gc_frame_newslot(*var_x33);
// compilenode returning *var_x34
  gc_frame_newslot(*var_x34);
// compilenode returning *var_x35
  gc_frame_newslot(*var_x35);
// compilenode returning *var_x36
  gc_frame_newslot(*var_x36);
// compilenode returning *var_x37
  gc_frame_newslot(*var_x37);
// compilenode returning *var_x38
  gc_frame_newslot(*var_x38);
// compilenode returning *var_x39
  gc_frame_newslot(*var_x39);
// compilenode returning *var_x40
  gc_frame_newslot(*var_x40);
// compilenode returning *var_x41
  gc_frame_newslot(*var_x41);
// compilenode returning *var_x42
  gc_frame_newslot(*var_x42);
// compilenode returning *var_x43
  gc_frame_newslot(*var_x43);
// compilenode returning *var_x44
  gc_frame_newslot(*var_x44);
// compilenode returning *var_x45
  gc_frame_newslot(*var_x45);
// compilenode returning *var_x46
  gc_frame_newslot(*var_x46);
// compilenode returning *var_x47
  gc_frame_newslot(*var_x47);
// compilenode returning *var_x48
  gc_frame_newslot(*var_x48);
// compilenode returning *var_x49
  gc_frame_newslot(*var_x49);
// compilenode returning *var_x50
  gc_frame_newslot(*var_x50);
// compilenode returning *var_x51
  gc_frame_newslot(*var_x51);
// compilenode returning *var_x52
  gc_frame_newslot(*var_x52);
// compilenode returning *var_x53
  gc_frame_newslot(*var_x53);
// compilenode returning *var_x54
  gc_frame_newslot(*var_x54);
// compilenode returning *var_x55
  gc_frame_newslot(*var_x55);
// compilenode returning *var_x56
  gc_frame_newslot(*var_x56);
// compilenode returning *var_x57
  gc_frame_newslot(*var_x57);
// compilenode returning *var_x58
  gc_frame_newslot(*var_x58);
// compilenode returning *var_x59
  gc_frame_newslot(*var_x59);
// compilenode returning *var_x60
  gc_frame_newslot(*var_x60);
// compilenode returning *var_x61
  gc_frame_newslot(*var_x61);
// compilenode returning *var_x62
  gc_frame_newslot(*var_x62);
// compilenode returning *var_x63
  gc_frame_newslot(*var_x63);
// compilenode returning *var_x64
  gc_frame_newslot(*var_x64);
  params[0] = *var_x33;
  params[1] = *var_x34;
  params[2] = *var_x35;
  params[3] = *var_x36;
  params[4] = *var_x37;
  params[5] = *var_x38;
  params[6] = *var_x39;
  params[7] = *var_x40;
  params[8] = *var_x41;
  params[9] = *var_x42;
  params[10] = *var_x43;
  params[11] = *var_x44;
  params[12] = *var_x45;
  params[13] = *var_x46;
  params[14] = *var_x47;
  params[15] = *var_x48;
  params[16] = *var_x49;
  params[17] = *var_x50;
  params[18] = *var_x51;
  params[19] = *var_x52;
  params[20] = *var_x53;
  params[21] = *var_x54;
  params[22] = *var_x55;
  params[23] = *var_x56;
  params[24] = *var_x57;
  params[25] = *var_x58;
  params[26] = *var_x59;
  params[27] = *var_x60;
  params[28] = *var_x61;
  params[29] = *var_x62;
  params[30] = *var_x63;
  params[31] = *var_x64;
  partcv[0] = 32;
  Object call396 = callmethodflags(self, "add32", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe395);
// compilenode returning call396
  int op_slot_right_392 = gc_frame_newslot(call396);
  params[0] = call396;
  partcv[0] = 1;
  Object sum398 = callmethod(call394, "+", 1, partcv, params);
// compilenode returning sum398
  return sum398;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add32399(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(33, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add32");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 32)
    gracedie("insufficient arguments to method");
  Object params[16];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *var_x5 = &(stackframe->slots[4]);
  *var_x5 = args[curarg];
  curarg++;
  Object *var_x6 = &(stackframe->slots[5]);
  *var_x6 = args[curarg];
  curarg++;
  Object *var_x7 = &(stackframe->slots[6]);
  *var_x7 = args[curarg];
  curarg++;
  Object *var_x8 = &(stackframe->slots[7]);
  *var_x8 = args[curarg];
  curarg++;
  Object *var_x9 = &(stackframe->slots[8]);
  *var_x9 = args[curarg];
  curarg++;
  Object *var_x10 = &(stackframe->slots[9]);
  *var_x10 = args[curarg];
  curarg++;
  Object *var_x11 = &(stackframe->slots[10]);
  *var_x11 = args[curarg];
  curarg++;
  Object *var_x12 = &(stackframe->slots[11]);
  *var_x12 = args[curarg];
  curarg++;
  Object *var_x13 = &(stackframe->slots[12]);
  *var_x13 = args[curarg];
  curarg++;
  Object *var_x14 = &(stackframe->slots[13]);
  *var_x14 = args[curarg];
  curarg++;
  Object *var_x15 = &(stackframe->slots[14]);
  *var_x15 = args[curarg];
  curarg++;
  Object *var_x16 = &(stackframe->slots[15]);
  *var_x16 = args[curarg];
  curarg++;
  Object *var_x17 = &(stackframe->slots[16]);
  *var_x17 = args[curarg];
  curarg++;
  Object *var_x18 = &(stackframe->slots[17]);
  *var_x18 = args[curarg];
  curarg++;
  Object *var_x19 = &(stackframe->slots[18]);
  *var_x19 = args[curarg];
  curarg++;
  Object *var_x20 = &(stackframe->slots[19]);
  *var_x20 = args[curarg];
  curarg++;
  Object *var_x21 = &(stackframe->slots[20]);
  *var_x21 = args[curarg];
  curarg++;
  Object *var_x22 = &(stackframe->slots[21]);
  *var_x22 = args[curarg];
  curarg++;
  Object *var_x23 = &(stackframe->slots[22]);
  *var_x23 = args[curarg];
  curarg++;
  Object *var_x24 = &(stackframe->slots[23]);
  *var_x24 = args[curarg];
  curarg++;
  Object *var_x25 = &(stackframe->slots[24]);
  *var_x25 = args[curarg];
  curarg++;
  Object *var_x26 = &(stackframe->slots[25]);
  *var_x26 = args[curarg];
  curarg++;
  Object *var_x27 = &(stackframe->slots[26]);
  *var_x27 = args[curarg];
  curarg++;
  Object *var_x28 = &(stackframe->slots[27]);
  *var_x28 = args[curarg];
  curarg++;
  Object *var_x29 = &(stackframe->slots[28]);
  *var_x29 = args[curarg];
  curarg++;
  Object *var_x30 = &(stackframe->slots[29]);
  *var_x30 = args[curarg];
  curarg++;
  Object *var_x31 = &(stackframe->slots[30]);
  *var_x31 = args[curarg];
  curarg++;
  Object *var_x32 = &(stackframe->slots[31]);
  *var_x32 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[32]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe401 = gc_frame_new();
// compilenode returning *var_x1
  gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  gc_frame_newslot(*var_x2);
// compilenode returning *var_x3
  gc_frame_newslot(*var_x3);
// compilenode returning *var_x4
  gc_frame_newslot(*var_x4);
// compilenode returning *var_x5
  gc_frame_newslot(*var_x5);
// compilenode returning *var_x6
  gc_frame_newslot(*var_x6);
// compilenode returning *var_x7
  gc_frame_newslot(*var_x7);
// compilenode returning *var_x8
  gc_frame_newslot(*var_x8);
// compilenode returning *var_x9
  gc_frame_newslot(*var_x9);
// compilenode returning *var_x10
  gc_frame_newslot(*var_x10);
// compilenode returning *var_x11
  gc_frame_newslot(*var_x11);
// compilenode returning *var_x12
  gc_frame_newslot(*var_x12);
// compilenode returning *var_x13
  gc_frame_newslot(*var_x13);
// compilenode returning *var_x14
  gc_frame_newslot(*var_x14);
// compilenode returning *var_x15
  gc_frame_newslot(*var_x15);
// compilenode returning *var_x16
  gc_frame_newslot(*var_x16);
  params[0] = *var_x1;
  params[1] = *var_x2;
  params[2] = *var_x3;
  params[3] = *var_x4;
  params[4] = *var_x5;
  params[5] = *var_x6;
  params[6] = *var_x7;
  params[7] = *var_x8;
  params[8] = *var_x9;
  params[9] = *var_x10;
  params[10] = *var_x11;
  params[11] = *var_x12;
  params[12] = *var_x13;
  params[13] = *var_x14;
  params[14] = *var_x15;
  params[15] = *var_x16;
  partcv[0] = 16;
  Object call402 = callmethodflags(self, "add16", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe401);
// compilenode returning call402
  int op_slot_left_400 = gc_frame_newslot(call402);
  int callframe403 = gc_frame_new();
// compilenode returning *var_x17
  gc_frame_newslot(*var_x17);
// compilenode returning *var_x18
  gc_frame_newslot(*var_x18);
// compilenode returning *var_x19
  gc_frame_newslot(*var_x19);
// compilenode returning *var_x20
  gc_frame_newslot(*var_x20);
// compilenode returning *var_x21
  gc_frame_newslot(*var_x21);
// compilenode returning *var_x22
  gc_frame_newslot(*var_x22);
// compilenode returning *var_x23
  gc_frame_newslot(*var_x23);
// compilenode returning *var_x24
  gc_frame_newslot(*var_x24);
// compilenode returning *var_x25
  gc_frame_newslot(*var_x25);
// compilenode returning *var_x26
  gc_frame_newslot(*var_x26);
// compilenode returning *var_x27
  gc_frame_newslot(*var_x27);
// compilenode returning *var_x28
  gc_frame_newslot(*var_x28);
// compilenode returning *var_x29
  gc_frame_newslot(*var_x29);
// compilenode returning *var_x30
  gc_frame_newslot(*var_x30);
// compilenode returning *var_x31
  gc_frame_newslot(*var_x31);
// compilenode returning *var_x32
  gc_frame_newslot(*var_x32);
  params[0] = *var_x17;
  params[1] = *var_x18;
  params[2] = *var_x19;
  params[3] = *var_x20;
  params[4] = *var_x21;
  params[5] = *var_x22;
  params[6] = *var_x23;
  params[7] = *var_x24;
  params[8] = *var_x25;
  params[9] = *var_x26;
  params[10] = *var_x27;
  params[11] = *var_x28;
  params[12] = *var_x29;
  params[13] = *var_x30;
  params[14] = *var_x31;
  params[15] = *var_x32;
  partcv[0] = 16;
  Object call404 = callmethodflags(self, "add16", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe403);
// compilenode returning call404
  int op_slot_right_400 = gc_frame_newslot(call404);
  params[0] = call404;
  partcv[0] = 1;
  Object sum406 = callmethod(call402, "+", 1, partcv, params);
// compilenode returning sum406
  return sum406;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add16407(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(17, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add16");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 16)
    gracedie("insufficient arguments to method");
  Object params[8];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *var_x5 = &(stackframe->slots[4]);
  *var_x5 = args[curarg];
  curarg++;
  Object *var_x6 = &(stackframe->slots[5]);
  *var_x6 = args[curarg];
  curarg++;
  Object *var_x7 = &(stackframe->slots[6]);
  *var_x7 = args[curarg];
  curarg++;
  Object *var_x8 = &(stackframe->slots[7]);
  *var_x8 = args[curarg];
  curarg++;
  Object *var_x9 = &(stackframe->slots[8]);
  *var_x9 = args[curarg];
  curarg++;
  Object *var_x10 = &(stackframe->slots[9]);
  *var_x10 = args[curarg];
  curarg++;
  Object *var_x11 = &(stackframe->slots[10]);
  *var_x11 = args[curarg];
  curarg++;
  Object *var_x12 = &(stackframe->slots[11]);
  *var_x12 = args[curarg];
  curarg++;
  Object *var_x13 = &(stackframe->slots[12]);
  *var_x13 = args[curarg];
  curarg++;
  Object *var_x14 = &(stackframe->slots[13]);
  *var_x14 = args[curarg];
  curarg++;
  Object *var_x15 = &(stackframe->slots[14]);
  *var_x15 = args[curarg];
  curarg++;
  Object *var_x16 = &(stackframe->slots[15]);
  *var_x16 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[16]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 17
  setline(17);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe409 = gc_frame_new();
// compilenode returning *var_x1
  gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  gc_frame_newslot(*var_x2);
// compilenode returning *var_x3
  gc_frame_newslot(*var_x3);
// compilenode returning *var_x4
  gc_frame_newslot(*var_x4);
// compilenode returning *var_x5
  gc_frame_newslot(*var_x5);
// compilenode returning *var_x6
  gc_frame_newslot(*var_x6);
// compilenode returning *var_x7
  gc_frame_newslot(*var_x7);
// compilenode returning *var_x8
  gc_frame_newslot(*var_x8);
  params[0] = *var_x1;
  params[1] = *var_x2;
  params[2] = *var_x3;
  params[3] = *var_x4;
  params[4] = *var_x5;
  params[5] = *var_x6;
  params[6] = *var_x7;
  params[7] = *var_x8;
  partcv[0] = 8;
  Object call410 = callmethodflags(self, "add8", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe409);
// compilenode returning call410
  int op_slot_left_408 = gc_frame_newslot(call410);
  int callframe411 = gc_frame_new();
// compilenode returning *var_x9
  gc_frame_newslot(*var_x9);
// compilenode returning *var_x10
  gc_frame_newslot(*var_x10);
// compilenode returning *var_x11
  gc_frame_newslot(*var_x11);
// compilenode returning *var_x12
  gc_frame_newslot(*var_x12);
// compilenode returning *var_x13
  gc_frame_newslot(*var_x13);
// compilenode returning *var_x14
  gc_frame_newslot(*var_x14);
// compilenode returning *var_x15
  gc_frame_newslot(*var_x15);
// compilenode returning *var_x16
  gc_frame_newslot(*var_x16);
  params[0] = *var_x9;
  params[1] = *var_x10;
  params[2] = *var_x11;
  params[3] = *var_x12;
  params[4] = *var_x13;
  params[5] = *var_x14;
  params[6] = *var_x15;
  params[7] = *var_x16;
  partcv[0] = 8;
  Object call412 = callmethodflags(self, "add8", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe411);
// compilenode returning call412
  int op_slot_right_408 = gc_frame_newslot(call412);
  params[0] = call412;
  partcv[0] = 1;
  Object sum414 = callmethod(call410, "+", 1, partcv, params);
// compilenode returning sum414
  return sum414;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add8415(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(9, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add8");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 8)
    gracedie("insufficient arguments to method");
  Object params[4];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *var_x5 = &(stackframe->slots[4]);
  *var_x5 = args[curarg];
  curarg++;
  Object *var_x6 = &(stackframe->slots[5]);
  *var_x6 = args[curarg];
  curarg++;
  Object *var_x7 = &(stackframe->slots[6]);
  *var_x7 = args[curarg];
  curarg++;
  Object *var_x8 = &(stackframe->slots[7]);
  *var_x8 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[8]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe417 = gc_frame_new();
// compilenode returning *var_x1
  gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  gc_frame_newslot(*var_x2);
// compilenode returning *var_x3
  gc_frame_newslot(*var_x3);
// compilenode returning *var_x4
  gc_frame_newslot(*var_x4);
  params[0] = *var_x1;
  params[1] = *var_x2;
  params[2] = *var_x3;
  params[3] = *var_x4;
  partcv[0] = 4;
  Object call418 = callmethodflags(self, "add4", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe417);
// compilenode returning call418
  int op_slot_left_416 = gc_frame_newslot(call418);
  int callframe419 = gc_frame_new();
// compilenode returning *var_x5
  gc_frame_newslot(*var_x5);
// compilenode returning *var_x6
  gc_frame_newslot(*var_x6);
// compilenode returning *var_x7
  gc_frame_newslot(*var_x7);
// compilenode returning *var_x8
  gc_frame_newslot(*var_x8);
  params[0] = *var_x5;
  params[1] = *var_x6;
  params[2] = *var_x7;
  params[3] = *var_x8;
  partcv[0] = 4;
  Object call420 = callmethodflags(self, "add4", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe419);
// compilenode returning call420
  int op_slot_right_416 = gc_frame_newslot(call420);
  params[0] = call420;
  partcv[0] = 1;
  Object sum422 = callmethod(call418, "+", 1, partcv, params);
// compilenode returning sum422
  return sum422;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add4423(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(5, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add4");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 4)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *var_x3 = &(stackframe->slots[2]);
  *var_x3 = args[curarg];
  curarg++;
  Object *var_x4 = &(stackframe->slots[3]);
  *var_x4 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[4]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe425 = gc_frame_new();
// compilenode returning *var_x1
  gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  gc_frame_newslot(*var_x2);
  params[0] = *var_x1;
  params[1] = *var_x2;
  partcv[0] = 2;
  Object call426 = callmethodflags(self, "add2", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe425);
// compilenode returning call426
  int op_slot_left_424 = gc_frame_newslot(call426);
  int callframe427 = gc_frame_new();
// compilenode returning *var_x3
  gc_frame_newslot(*var_x3);
// compilenode returning *var_x4
  gc_frame_newslot(*var_x4);
  params[0] = *var_x3;
  params[1] = *var_x4;
  partcv[0] = 2;
  Object call428 = callmethodflags(self, "add2", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe427);
// compilenode returning call428
  int op_slot_right_424 = gc_frame_newslot(call428);
  params[0] = call428;
  partcv[0] = 1;
  Object sum430 = callmethod(call426, "+", 1, partcv, params);
// compilenode returning sum430
  return sum430;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_add2431(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(3, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "add2");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 2)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_x1 = &(stackframe->slots[0]);
  *var_x1 = args[curarg];
  curarg++;
  Object *var_x2 = &(stackframe->slots[1]);
  *var_x2 = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[2]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 27
  setline(27);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 26
  setline(26);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_x1
  int op_slot_left_432 = gc_frame_newslot(*var_x1);
// compilenode returning *var_x2
  int op_slot_right_432 = gc_frame_newslot(*var_x2);
  params[0] = *var_x2;
  partcv[0] = 1;
  Object sum434 = callmethod(*var_x1, "+", 1, partcv, params);
// compilenode returning sum434
  return sum434;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_adder_main435(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(1, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "main");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 29
  setline(29);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe436 = gc_frame_new();
  partcv[0] = 0;
  Object call437 = callmethodflags(self, "concreteadd", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe436);
// compilenode returning call437
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe438 = gc_frame_new();
  partcv[0] = 0;
  Object call439 = callmethodflags(self, "inlineadd", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe438);
// compilenode returning call439
  gc_frame_end(frame);
  return call439;
}
Object meth_lig_47_adder__apply461(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_x = getfromclosure(closure, 0);
  Object self = *(getfromclosure(closure, 1));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_i = &(stackframe->slots[0]);
  *var_i = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 40
  setline(40);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 62
  setline(62);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num462 = alloc_Float64(16512);
// compilenode returning num462
  *var_x = num462;
  if (num462 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_adder__apply450(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_sys = getfromclosure(closure, 0);
  Object *var_time = getfromclosure(closure, 1);
  Object *var_x = getfromclosure(closure, 2);
  Object *var_avg = getfromclosure(closure, 3);
  Object self = *(getfromclosure(closure, 4));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_n = &(stackframe->slots[0]);
  *var_n = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 38
  setline(38);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe451 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call452 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe451);
// compilenode returning call452
// compilenode returning call452
  *var_time = call452;
  if (call452 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe454 = gc_frame_new();
  Object num456 = alloc_Float64(1);
// compilenode returning num456
  int op_slot_left_455 = gc_frame_newslot(num456);
  Object num457 = alloc_Float64(1000);
// compilenode returning num457
  int op_slot_right_455 = gc_frame_newslot(num457);
  params[0] = num457;
  partcv[0] = 1;
  Object opresult459 = callmethod(num456, "..", 1, partcv, params);
// compilenode returning opresult459
  gc_frame_newslot(opresult459);
  Object block460 = alloc_Block(NULL, NULL, "lig/adder", 39);
  gc_frame_newslot(block460);
  block_savedest(block460);
  Object closure461 = createclosure(2, "_apply");
setclosureframe(closure461, stackframe);
  addtoclosure(closure461, var_x);
  addtoclosure(closure461, selfslot);
  struct UserObject *uo461 = (struct UserObject*)block460;
  uo461->data[0] = (Object)closure461;
  Method *meth_meth_lig_47_adder__apply461 = addmethod2pos(block460, "_apply", &meth_lig_47_adder__apply461, 0);
int argcv_meth_lig_47_adder__apply461[] = {1};
meth_meth_lig_47_adder__apply461->type = alloc_MethodType(1, argcv_meth_lig_47_adder__apply461);
  meth_meth_lig_47_adder__apply461->definitionModule = modulename;
  meth_meth_lig_47_adder__apply461->definitionLine = 38;
// compilenode returning block460
  gc_frame_newslot(block460);
  params[0] = opresult459;
  params[1] = block460;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call465 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe454);
// compilenode returning call465
// Begin line 43
  setline(43);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 42
  setline(42);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_avg
  int op_slot_left_466 = gc_frame_newslot(*var_avg);
  int callframe468 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call469 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe468);
// compilenode returning call469
// compilenode returning call469
  int op_slot_left_467 = gc_frame_newslot(call469);
// compilenode returning *var_time
  int op_slot_right_467 = gc_frame_newslot(*var_time);
  params[0] = *var_time;
  partcv[0] = 1;
  Object diff471 = callmethod(call469, "-", 1, partcv, params);
// compilenode returning diff471
  int op_slot_right_466 = gc_frame_newslot(diff471);
  params[0] = diff471;
  partcv[0] = 1;
  Object sum473 = callmethod(*var_avg, "+", 1, partcv, params);
// compilenode returning sum473
  *var_avg = sum473;
  if (sum473 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_adder_concreteadd440(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 11, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(5, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "concreteadd");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_sys = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_avg = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "avg");
  Object *var_num = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "num");
  Object *var_time = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "time");
  Object *var_x = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "x");
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num441 = alloc_Float64(0);
// compilenode returning num441
  *var_avg = num441;
  if (num441 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 34
  setline(34);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num442 = alloc_Float64(15);
// compilenode returning num442
  *var_num = num442;
  if (num442 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 35
  setline(35);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_time = undefined;
// compilenode returning none
// Begin line 36
  setline(36);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num443 = alloc_Float64(0);
// compilenode returning num443
  *var_x = num443;
  if (num443 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 37
  setline(37);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe444 = gc_frame_new();
  Object num446 = alloc_Float64(1);
// compilenode returning num446
  int op_slot_left_445 = gc_frame_newslot(num446);
// compilenode returning *var_num
  int op_slot_right_445 = gc_frame_newslot(*var_num);
  params[0] = *var_num;
  partcv[0] = 1;
  Object opresult448 = callmethod(num446, "..", 1, partcv, params);
// compilenode returning opresult448
  gc_frame_newslot(opresult448);
  Object block449 = alloc_Block(NULL, NULL, "lig/adder", 37);
  gc_frame_newslot(block449);
  block_savedest(block449);
  Object closure450 = createclosure(5, "_apply");
setclosureframe(closure450, stackframe);
  addtoclosure(closure450, var_sys);
  addtoclosure(closure450, var_time);
  addtoclosure(closure450, var_x);
  addtoclosure(closure450, var_avg);
  addtoclosure(closure450, selfslot);
  struct UserObject *uo450 = (struct UserObject*)block449;
  uo450->data[0] = (Object)closure450;
  Method *meth_meth_lig_47_adder__apply450 = addmethod2pos(block449, "_apply", &meth_lig_47_adder__apply450, 0);
int argcv_meth_lig_47_adder__apply450[] = {1};
meth_meth_lig_47_adder__apply450->type = alloc_MethodType(1, argcv_meth_lig_47_adder__apply450);
  meth_meth_lig_47_adder__apply450->definitionModule = modulename;
  meth_meth_lig_47_adder__apply450->definitionLine = 62;
// compilenode returning block449
  gc_frame_newslot(block449);
  params[0] = opresult448;
  params[1] = block449;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call476 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe444);
// compilenode returning call476
// Begin line 45
  setline(45);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit481 == NULL) {
    strlit481 = alloc_String("annotated concrete average of ");
    gc_root(strlit481);
  }
// compilenode returning strlit481
  int op_slot_left_480 = gc_frame_newslot(strlit481);
// compilenode returning *var_num
  int op_slot_right_480 = gc_frame_newslot(*var_num);
  params[0] = *var_num;
  partcv[0] = 1;
  Object opresult483 = callmethod(strlit481, "++", 1, partcv, params);
// compilenode returning opresult483
  int op_slot_left_479 = gc_frame_newslot(opresult483);
  if (strlit484 == NULL) {
    strlit484 = alloc_String(": ");
    gc_root(strlit484);
  }
// compilenode returning strlit484
  int op_slot_right_479 = gc_frame_newslot(strlit484);
  params[0] = strlit484;
  partcv[0] = 1;
  Object opresult486 = callmethod(opresult483, "++", 1, partcv, params);
// compilenode returning opresult486
  int op_slot_left_478 = gc_frame_newslot(opresult486);
// compilenode returning *var_avg
  int op_slot_left_487 = gc_frame_newslot(*var_avg);
// compilenode returning *var_num
  int op_slot_right_487 = gc_frame_newslot(*var_num);
  params[0] = *var_num;
  partcv[0] = 1;
  Object quotient489 = callmethod(*var_avg, "/", 1, partcv, params);
// compilenode returning quotient489
  int op_slot_right_478 = gc_frame_newslot(quotient489);
  params[0] = quotient489;
  partcv[0] = 1;
  Object opresult491 = callmethod(opresult486, "++", 1, partcv, params);
// compilenode returning opresult491
  int op_slot_left_477 = gc_frame_newslot(opresult491);
  if (strlit492 == NULL) {
    strlit492 = alloc_String("s");
    gc_root(strlit492);
  }
// compilenode returning strlit492
  int op_slot_right_477 = gc_frame_newslot(strlit492);
  params[0] = strlit492;
  partcv[0] = 1;
  Object opresult494 = callmethod(opresult491, "++", 1, partcv, params);
// compilenode returning opresult494
  params[0] = opresult494;
  Object call495 = gracelib_print(NULL, 1,  params);
// compilenode returning call495
  gc_frame_end(frame);
  return call495;
}
Object meth_lig_47_adder__apply517(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_x = getfromclosure(closure, 0);
  Object self = *(getfromclosure(closure, 1));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_z = &(stackframe->slots[0]);
  *var_z = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 55
  setline(55);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 62
  setline(62);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num518 = alloc_Float64(16512);
// compilenode returning num518
  *var_x = num518;
  if (num518 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_adder__apply506(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_sys = getfromclosure(closure, 0);
  Object *var_time = getfromclosure(closure, 1);
  Object *var_x = getfromclosure(closure, 2);
  Object *var_avg = getfromclosure(closure, 3);
  Object self = *(getfromclosure(closure, 4));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_n = &(stackframe->slots[0]);
  *var_n = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 54
  setline(54);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 53
  setline(53);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe507 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call508 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe507);
// compilenode returning call508
// compilenode returning call508
  *var_time = call508;
  if (call508 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 54
  setline(54);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe510 = gc_frame_new();
  Object num512 = alloc_Float64(1);
// compilenode returning num512
  int op_slot_left_511 = gc_frame_newslot(num512);
  Object num513 = alloc_Float64(1000);
// compilenode returning num513
  int op_slot_right_511 = gc_frame_newslot(num513);
  params[0] = num513;
  partcv[0] = 1;
  Object opresult515 = callmethod(num512, "..", 1, partcv, params);
// compilenode returning opresult515
  gc_frame_newslot(opresult515);
  Object block516 = alloc_Block(NULL, NULL, "lig/adder", 54);
  gc_frame_newslot(block516);
  block_savedest(block516);
  Object closure517 = createclosure(2, "_apply");
setclosureframe(closure517, stackframe);
  addtoclosure(closure517, var_x);
  addtoclosure(closure517, selfslot);
  struct UserObject *uo517 = (struct UserObject*)block516;
  uo517->data[0] = (Object)closure517;
  Method *meth_meth_lig_47_adder__apply517 = addmethod2pos(block516, "_apply", &meth_lig_47_adder__apply517, 0);
int argcv_meth_lig_47_adder__apply517[] = {1};
meth_meth_lig_47_adder__apply517->type = alloc_MethodType(1, argcv_meth_lig_47_adder__apply517);
  meth_meth_lig_47_adder__apply517->definitionModule = modulename;
  meth_meth_lig_47_adder__apply517->definitionLine = 53;
// compilenode returning block516
  gc_frame_newslot(block516);
  params[0] = opresult515;
  params[1] = block516;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call521 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe510);
// compilenode returning call521
// Begin line 58
  setline(58);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 57
  setline(57);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_avg
  int op_slot_left_522 = gc_frame_newslot(*var_avg);
  int callframe524 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call525 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe524);
// compilenode returning call525
// compilenode returning call525
  int op_slot_left_523 = gc_frame_newslot(call525);
// compilenode returning *var_time
  int op_slot_right_523 = gc_frame_newslot(*var_time);
  params[0] = *var_time;
  partcv[0] = 1;
  Object diff527 = callmethod(call525, "-", 1, partcv, params);
// compilenode returning diff527
  int op_slot_right_522 = gc_frame_newslot(diff527);
  params[0] = diff527;
  partcv[0] = 1;
  Object sum529 = callmethod(*var_avg, "+", 1, partcv, params);
// compilenode returning sum529
  *var_avg = sum529;
  if (sum529 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_adder_inlineadd496(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 12, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(5, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "inlineadd");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_sys = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_avg = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "avg");
  Object *var_num = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "num");
  Object *var_time = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "time");
  Object *var_x = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "x");
// Begin line 48
  setline(48);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num497 = alloc_Float64(0);
// compilenode returning num497
  *var_avg = num497;
  if (num497 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 49
  setline(49);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num498 = alloc_Float64(15);
// compilenode returning num498
  *var_num = num498;
  if (num498 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 50
  setline(50);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_time = undefined;
// compilenode returning none
// Begin line 51
  setline(51);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num499 = alloc_Float64(0);
// compilenode returning num499
  *var_x = num499;
  if (num499 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 52
  setline(52);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe500 = gc_frame_new();
  Object num502 = alloc_Float64(1);
// compilenode returning num502
  int op_slot_left_501 = gc_frame_newslot(num502);
// compilenode returning *var_num
  int op_slot_right_501 = gc_frame_newslot(*var_num);
  params[0] = *var_num;
  partcv[0] = 1;
  Object opresult504 = callmethod(num502, "..", 1, partcv, params);
// compilenode returning opresult504
  gc_frame_newslot(opresult504);
  Object block505 = alloc_Block(NULL, NULL, "lig/adder", 52);
  gc_frame_newslot(block505);
  block_savedest(block505);
  Object closure506 = createclosure(5, "_apply");
setclosureframe(closure506, stackframe);
  addtoclosure(closure506, var_sys);
  addtoclosure(closure506, var_time);
  addtoclosure(closure506, var_x);
  addtoclosure(closure506, var_avg);
  addtoclosure(closure506, selfslot);
  struct UserObject *uo506 = (struct UserObject*)block505;
  uo506->data[0] = (Object)closure506;
  Method *meth_meth_lig_47_adder__apply506 = addmethod2pos(block505, "_apply", &meth_lig_47_adder__apply506, 0);
int argcv_meth_lig_47_adder__apply506[] = {1};
meth_meth_lig_47_adder__apply506->type = alloc_MethodType(1, argcv_meth_lig_47_adder__apply506);
  meth_meth_lig_47_adder__apply506->definitionModule = modulename;
  meth_meth_lig_47_adder__apply506->definitionLine = 42;
// compilenode returning block505
  gc_frame_newslot(block505);
  params[0] = opresult504;
  params[1] = block505;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call532 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe500);
// compilenode returning call532
// Begin line 60
  setline(60);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit537 == NULL) {
    strlit537 = alloc_String("inline average of ");
    gc_root(strlit537);
  }
// compilenode returning strlit537
  int op_slot_left_536 = gc_frame_newslot(strlit537);
// compilenode returning *var_num
  int op_slot_right_536 = gc_frame_newslot(*var_num);
  params[0] = *var_num;
  partcv[0] = 1;
  Object opresult539 = callmethod(strlit537, "++", 1, partcv, params);
// compilenode returning opresult539
  int op_slot_left_535 = gc_frame_newslot(opresult539);
  if (strlit540 == NULL) {
    strlit540 = alloc_String(": ");
    gc_root(strlit540);
  }
// compilenode returning strlit540
  int op_slot_right_535 = gc_frame_newslot(strlit540);
  params[0] = strlit540;
  partcv[0] = 1;
  Object opresult542 = callmethod(opresult539, "++", 1, partcv, params);
// compilenode returning opresult542
  int op_slot_left_534 = gc_frame_newslot(opresult542);
// compilenode returning *var_avg
  int op_slot_left_543 = gc_frame_newslot(*var_avg);
// compilenode returning *var_num
  int op_slot_right_543 = gc_frame_newslot(*var_num);
  params[0] = *var_num;
  partcv[0] = 1;
  Object quotient545 = callmethod(*var_avg, "/", 1, partcv, params);
// compilenode returning quotient545
  int op_slot_right_534 = gc_frame_newslot(quotient545);
  params[0] = quotient545;
  partcv[0] = 1;
  Object opresult547 = callmethod(opresult542, "++", 1, partcv, params);
// compilenode returning opresult547
  int op_slot_left_533 = gc_frame_newslot(opresult547);
  if (strlit548 == NULL) {
    strlit548 = alloc_String("s");
    gc_root(strlit548);
  }
// compilenode returning strlit548
  int op_slot_right_533 = gc_frame_newslot(strlit548);
  params[0] = strlit548;
  partcv[0] = 1;
  Object opresult550 = callmethod(opresult547, "++", 1, partcv, params);
// compilenode returning opresult550
  params[0] = opresult550;
  Object call551 = gracelib_print(NULL, 1,  params);
// compilenode returning call551
  gc_frame_end(frame);
  return call551;
}
Object module_lig_47_adder_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(14, 14);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/adder>");
  Object *var_MatchFailed = alloc_var();
  *var_MatchFailed = alloc_MatchFailed();
  Object *var_noSuchValue = alloc_var();
  *var_noSuchValue = none;
  Object *var_done = alloc_var();
  *var_done = none;
  Object *var_nothing = alloc_var();
  *var_nothing = none;
  Object *var_String = alloc_var();
  *var_String = String;
  type_String = String;
  Object *var_Block = alloc_var();
  *var_Block = Block;
  type_Block = Block;
  Object *var_Void = alloc_var();
  *var_Void = None;
  type_Void = None;
  Object *var_None = alloc_var();
  *var_None = None;
  type_None = None;
  Object *var_Number = alloc_var();
  *var_Number = Number;
  type_Number = Number;
  Object *var_Boolean = alloc_var();
  *var_Boolean = Boolean;
  type_Boolean = Boolean;
  Object *var_Dynamic = alloc_var();
  *var_Dynamic = Dynamic;
  Object *var_Type = alloc_var();
  *var_Type = Type;
  Object *var__prelude = alloc_var();
  *var__prelude = grace_prelude();
  gc_root(*var_MatchFailed);
  emptyclosure = createclosure(0, "empty");
  gc_root(emptyclosure);
  struct StackFrameObject *stackframe = alloc_StackFrame(14, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[1];
  int partcv[1];
Object *var_sys = alloc_var();
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = emptyclosure;
  Method *meth_meth_lig_47_adder_inline0 = addmethod2pos(self, "inline", &meth_lig_47_adder_inline0, 1);
int argcv_meth_lig_47_adder_inline0[] = {0};
meth_meth_lig_47_adder_inline0->type = alloc_MethodType(1, argcv_meth_lig_47_adder_inline0);
  meth_meth_lig_47_adder_inline0->definitionModule = modulename;
  meth_meth_lig_47_adder_inline0->definitionLine = 2;
// compilenode returning 
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[2] = emptyclosure;
  Method *meth_meth_lig_47_adder_add128i1 = addmethod2pos(self, "add128i", &meth_lig_47_adder_add128i1, 2);
int argcv_meth_lig_47_adder_add128i1[] = {128};
meth_meth_lig_47_adder_add128i1->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add128i1);
  meth_meth_lig_47_adder_add128i1->definitionModule = modulename;
  meth_meth_lig_47_adder_add128i1->definitionLine = 4;
// compilenode returning 
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo383 = (struct UserObject*)self;
  uo383->data[3] = emptyclosure;
  Method *meth_meth_lig_47_adder_add128383 = addmethod2pos(self, "add128", &meth_lig_47_adder_add128383, 3);
int argcv_meth_lig_47_adder_add128383[] = {128};
meth_meth_lig_47_adder_add128383->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add128383);
  meth_meth_lig_47_adder_add128383->definitionModule = modulename;
  meth_meth_lig_47_adder_add128383->definitionLine = 7;
// compilenode returning 
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo391 = (struct UserObject*)self;
  uo391->data[4] = emptyclosure;
  Method *meth_meth_lig_47_adder_add64391 = addmethod2pos(self, "add64", &meth_lig_47_adder_add64391, 4);
int argcv_meth_lig_47_adder_add64391[] = {64};
meth_meth_lig_47_adder_add64391->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add64391);
  meth_meth_lig_47_adder_add64391->definitionModule = modulename;
  meth_meth_lig_47_adder_add64391->definitionLine = 10;
// compilenode returning 
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo399 = (struct UserObject*)self;
  uo399->data[5] = emptyclosure;
  Method *meth_meth_lig_47_adder_add32399 = addmethod2pos(self, "add32", &meth_lig_47_adder_add32399, 5);
int argcv_meth_lig_47_adder_add32399[] = {32};
meth_meth_lig_47_adder_add32399->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add32399);
  meth_meth_lig_47_adder_add32399->definitionModule = modulename;
  meth_meth_lig_47_adder_add32399->definitionLine = 13;
// compilenode returning 
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo407 = (struct UserObject*)self;
  uo407->data[6] = emptyclosure;
  Method *meth_meth_lig_47_adder_add16407 = addmethod2pos(self, "add16", &meth_lig_47_adder_add16407, 6);
int argcv_meth_lig_47_adder_add16407[] = {16};
meth_meth_lig_47_adder_add16407->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add16407);
  meth_meth_lig_47_adder_add16407->definitionModule = modulename;
  meth_meth_lig_47_adder_add16407->definitionLine = 16;
// compilenode returning 
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo415 = (struct UserObject*)self;
  uo415->data[7] = emptyclosure;
  Method *meth_meth_lig_47_adder_add8415 = addmethod2pos(self, "add8", &meth_lig_47_adder_add8415, 7);
int argcv_meth_lig_47_adder_add8415[] = {8};
meth_meth_lig_47_adder_add8415->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add8415);
  meth_meth_lig_47_adder_add8415->definitionModule = modulename;
  meth_meth_lig_47_adder_add8415->definitionLine = 19;
// compilenode returning 
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo423 = (struct UserObject*)self;
  uo423->data[8] = emptyclosure;
  Method *meth_meth_lig_47_adder_add4423 = addmethod2pos(self, "add4", &meth_lig_47_adder_add4423, 8);
int argcv_meth_lig_47_adder_add4423[] = {4};
meth_meth_lig_47_adder_add4423->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add4423);
  meth_meth_lig_47_adder_add4423->definitionModule = modulename;
  meth_meth_lig_47_adder_add4423->definitionLine = 22;
// compilenode returning 
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo431 = (struct UserObject*)self;
  uo431->data[9] = emptyclosure;
  Method *meth_meth_lig_47_adder_add2431 = addmethod2pos(self, "add2", &meth_lig_47_adder_add2431, 9);
int argcv_meth_lig_47_adder_add2431[] = {2};
meth_meth_lig_47_adder_add2431->type = alloc_MethodType(1, argcv_meth_lig_47_adder_add2431);
  meth_meth_lig_47_adder_add2431->definitionModule = modulename;
  meth_meth_lig_47_adder_add2431->definitionLine = 25;
// compilenode returning 
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo435 = (struct UserObject*)self;
  uo435->data[10] = emptyclosure;
  Method *meth_meth_lig_47_adder_main435 = addmethod2pos(self, "main", &meth_lig_47_adder_main435, 10);
int argcv_meth_lig_47_adder_main435[] = {0};
meth_meth_lig_47_adder_main435->type = alloc_MethodType(1, argcv_meth_lig_47_adder_main435);
  meth_meth_lig_47_adder_main435->definitionModule = modulename;
  meth_meth_lig_47_adder_main435->definitionLine = 28;
// compilenode returning 
// Begin line 32
  setline(32);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure440 = createclosure(1, "concreteadd");
setclosureframe(closure440, stackframe);
  addtoclosure(closure440, var_sys);
  struct UserObject *uo440 = (struct UserObject*)self;
  uo440->data[11] = (Object)closure440;
  Method *meth_meth_lig_47_adder_concreteadd440 = addmethod2pos(self, "concreteadd", &meth_lig_47_adder_concreteadd440, 11);
int argcv_meth_lig_47_adder_concreteadd440[] = {0};
meth_meth_lig_47_adder_concreteadd440->type = alloc_MethodType(1, argcv_meth_lig_47_adder_concreteadd440);
  meth_meth_lig_47_adder_concreteadd440->definitionModule = modulename;
  meth_meth_lig_47_adder_concreteadd440->definitionLine = 32;
// compilenode returning 
// Begin line 47
  setline(47);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure496 = createclosure(1, "inlineadd");
setclosureframe(closure496, stackframe);
  addtoclosure(closure496, var_sys);
  struct UserObject *uo496 = (struct UserObject*)self;
  uo496->data[12] = (Object)closure496;
  Method *meth_meth_lig_47_adder_inlineadd496 = addmethod2pos(self, "inlineadd", &meth_lig_47_adder_inlineadd496, 12);
int argcv_meth_lig_47_adder_inlineadd496[] = {0};
meth_meth_lig_47_adder_inlineadd496->type = alloc_MethodType(1, argcv_meth_lig_47_adder_inlineadd496);
  meth_meth_lig_47_adder_inlineadd496->definitionModule = modulename;
  meth_meth_lig_47_adder_inlineadd496->definitionLine = 47;
// compilenode returning 
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
// Import of sys as sys
  if (module_sys == NULL)
    module_sys = module_sys_init();
  *var_sys = module_sys;
// compilenode returning none
// Begin line 62
  setline(62);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe552 = gc_frame_new();
  partcv[0] = 0;
  Object call553 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe552);
// compilenode returning call553
  gc_frame_end(frame);
  return self;
}
int main(int argc, char **argv) {
  initprofiling();
  setCompilerModulePath("/home/ligands/git/minigrace");
  gracelib_argv(argv);
  Object params[1];
  undefined = alloc_Undefined();
  none = alloc_none();
  Object tmp_argv = alloc_List();
  gc_root(tmp_argv);
  int partcv_push[] = {1};
  int i; for (i=0; i<argc; i++) {
    params[0] = alloc_String(argv[i]);
    callmethod(tmp_argv, "push", 1, partcv_push, params);
  }
  module_sys_init_argv(tmp_argv);
  module_lig_47_adder_init();
  gracelib_stats();
  return 0;
}
