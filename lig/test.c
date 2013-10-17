#include <gracelib.h>
#include <stdlib.h>
#ifndef __CYGWIN__
#pragma weak main
#endif
static char compilerRevision[] = "2f33f70cec8f2392593abe0f690fe1d68e938c1c";
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
static const char modulename[] = "lig/test";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "#pragma DefaultVisibility=public",
  "var orig := -1",
  "method inline{}",
  "",
  "method namingConflict() is inline{",
  "    var foo := \"name conflicts okay 1\"",
  "    print(foo)",
  "}",
  "",
  "var recur := 0",
  "method recurse(a) is inline {",
  "    if(a < 1) then {",
  "        orig := -1",
  "        return true",
  "    }",
  "    if(orig < 0) then {",
  "        orig := a",
  "    }",
  "    recur := recur + ((orig-a)+1)",
  "    recurse(a-1)",
  "}",
  "",
  "method constantProp2(a) is inline {",
  "    var b := a - 2",
  "    return (b + 7)",
  "}",
  "",
  "method constantProp1() is inline{",
  "    var a := 29 + 1",
  "    var b := 9 - (a / 5);",
  "    var c ",
  "    c := b * 4",
  "    var d := true || false",
  "    d := true.orElse{false}",
  "    if(c > 10) then{",
  "        c := c - 10",
  "    }",
  "    return c * (60 / a)",
  "}",
  "",
  "method multiLine() is inline {",
  "    var a := 1",
  "    var b := 2",
  "    if((a+b) == 3) then {",
  "        print(\"multi-line okay\")",
  "    } else {",
  "        print(\"multi-line FAIL\")",
  "    }",
  "}",
  "",
  "method main(){",
  "    recurse(4)",
  "    if(recur == 10) then {",
  "        print(\"recursive okay\")",
  "    } else {",
  "        print(\"recursive FAIL\")",
  "    }",
  "    ",
  "    multiLine",
  "    ",
  "    var foo := \"name conflicts okay 2\"",
  "    namingConflict",
  "    print(foo)",
  "    ",
  "    constantProp1()",
  "    ",
  "    var a := 5",
  "    var b := constantProp2(a+3)",
  "    if(b == 13) then {",
  "        print(\"constantProp_Test\")",
  "    } else {",
  "        print(\"constantProp_Test FAIL\")",
  "    }",
  "}",
  "",
  "main()",
  NULL
};
static Object strlit2;
static Object strlit107;
static Object strlit109;
static Object strlit120;
static Object strlit122;
static Object strlit136;
static Object strlit138;
static Object strlit140;
static Object strlit141;
static Object strlit142;
static Object strlit188;
static Object strlit190;
Object meth_lig_47_test_inline0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
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
Object meth_lig_47_test_namingConflict1(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(2, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "namingConflict");
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
  Object *var_foo = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "foo");
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit2 == NULL) {
    strlit2 = alloc_String("name conflicts okay 1");
    gc_root(strlit2);
  }
// compilenode returning strlit2
  *var_foo = strlit2;
  if (strlit2 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_foo
  params[0] = *var_foo;
  Object call3 = gracelib_print(NULL, 1,  params);
// compilenode returning call3
  gc_frame_end(frame);
  return call3;
}
Object meth_lig_47_test_recurse4(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 3, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "recurse");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_orig = getfromclosure(closure, 0);
  Object *var_recur = getfromclosure(closure, 1);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_a = &(stackframe->slots[0]);
  *var_a = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  int op_slot_left_6 = gc_frame_newslot(*var_a);
  Object num7 = alloc_Float64(1);
// compilenode returning num7
  int op_slot_right_6 = gc_frame_newslot(num7);
  params[0] = num7;
  partcv[0] = 1;
  Object opresult9 = callmethod(*var_a, "<", 1, partcv, params);
// compilenode returning opresult9
  Object if5 = none;
  if (istrue(opresult9)) {
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe10 = gc_frame_new();
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num11 = alloc_Float64(1);
// compilenode returning num11
  partcv[0] = 0;
  Object call12 = callmethod(num11, "prefix-",
    1, partcv, params);
  gc_frame_end(callframe10);
// compilenode returning call12
  *var_orig = call12;
  if (call12 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 15
  setline(15);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool14 = alloc_Boolean(1);
// compilenode returning bool14
  return bool14;
// compilenode returning undefined
    gc_frame_newslot(undefined);
    if5 = undefined;
  } else {
  }
// compilenode returning if5
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_orig
  int op_slot_left_16 = gc_frame_newslot(*var_orig);
  Object num17 = alloc_Float64(0);
// compilenode returning num17
  int op_slot_right_16 = gc_frame_newslot(num17);
  params[0] = num17;
  partcv[0] = 1;
  Object opresult19 = callmethod(*var_orig, "<", 1, partcv, params);
// compilenode returning opresult19
  Object if15 = none;
  if (istrue(opresult19)) {
// Begin line 18
  setline(18);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 17
  setline(17);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  *var_orig = *var_a;
  if (*var_a == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if15 = none;
  } else {
  }
// compilenode returning if15
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_recur
  int op_slot_left_21 = gc_frame_newslot(*var_recur);
// compilenode returning *var_orig
  int op_slot_left_23 = gc_frame_newslot(*var_orig);
// compilenode returning *var_a
  int op_slot_right_23 = gc_frame_newslot(*var_a);
  params[0] = *var_a;
  partcv[0] = 1;
  Object diff25 = callmethod(*var_orig, "-", 1, partcv, params);
// compilenode returning diff25
  int op_slot_left_22 = gc_frame_newslot(diff25);
  Object num26 = alloc_Float64(1);
// compilenode returning num26
  int op_slot_right_22 = gc_frame_newslot(num26);
  params[0] = num26;
  partcv[0] = 1;
  Object sum28 = callmethod(diff25, "+", 1, partcv, params);
// compilenode returning sum28
  int op_slot_right_21 = gc_frame_newslot(sum28);
  params[0] = sum28;
  partcv[0] = 1;
  Object sum30 = callmethod(*var_recur, "+", 1, partcv, params);
// compilenode returning sum30
  *var_recur = sum30;
  if (sum30 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe32 = gc_frame_new();
// compilenode returning *var_a
  int op_slot_left_33 = gc_frame_newslot(*var_a);
  Object num34 = alloc_Float64(1);
// compilenode returning num34
  int op_slot_right_33 = gc_frame_newslot(num34);
  params[0] = num34;
  partcv[0] = 1;
  Object diff36 = callmethod(*var_a, "-", 1, partcv, params);
// compilenode returning diff36
  gc_frame_newslot(diff36);
  params[0] = diff36;
  partcv[0] = 1;
  Object call37 = callmethodflags(self, "recurse", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe32);
// compilenode returning call37
  gc_frame_end(frame);
  return call37;
}
Object meth_lig_47_test_constantProp238(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(3, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "constantProp2");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_a = &(stackframe->slots[0]);
  *var_a = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_b = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "b");
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  int op_slot_left_39 = gc_frame_newslot(*var_a);
  Object num40 = alloc_Float64(2);
// compilenode returning num40
  int op_slot_right_39 = gc_frame_newslot(num40);
  params[0] = num40;
  partcv[0] = 1;
  Object diff42 = callmethod(*var_a, "-", 1, partcv, params);
// compilenode returning diff42
  *var_b = diff42;
  if (diff42 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 26
  setline(26);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  int op_slot_left_43 = gc_frame_newslot(*var_b);
  Object num44 = alloc_Float64(7);
// compilenode returning num44
  int op_slot_right_43 = gc_frame_newslot(num44);
  params[0] = num44;
  partcv[0] = 1;
  Object sum46 = callmethod(*var_b, "+", 1, partcv, params);
// compilenode returning sum46
  return sum46;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_test__apply73(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object self = *(getfromclosure(closure, 0));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object bool74 = alloc_Boolean(0);
// compilenode returning bool74
  gc_frame_end(frame);
  return bool74;
}
Object meth_lig_47_test_constantProp147(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(5, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "constantProp1");
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
  Object *var_a = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "a");
  Object *var_b = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "b");
  Object *var_c = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "c");
  Object *var_d = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "d");
// Begin line 29
  setline(29);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 29
  setline(29);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num49 = alloc_Float64(29);
// compilenode returning num49
  int op_slot_left_48 = gc_frame_newslot(num49);
  Object num50 = alloc_Float64(1);
// compilenode returning num50
  int op_slot_right_48 = gc_frame_newslot(num50);
  params[0] = num50;
  partcv[0] = 1;
  Object sum52 = callmethod(num49, "+", 1, partcv, params);
// compilenode returning sum52
  *var_a = sum52;
  if (sum52 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num54 = alloc_Float64(9);
// compilenode returning num54
  int op_slot_left_53 = gc_frame_newslot(num54);
// compilenode returning *var_a
  int op_slot_left_55 = gc_frame_newslot(*var_a);
  Object num56 = alloc_Float64(5);
// compilenode returning num56
  int op_slot_right_55 = gc_frame_newslot(num56);
  params[0] = num56;
  partcv[0] = 1;
  Object quotient58 = callmethod(*var_a, "/", 1, partcv, params);
// compilenode returning quotient58
  int op_slot_right_53 = gc_frame_newslot(quotient58);
  params[0] = quotient58;
  partcv[0] = 1;
  Object diff60 = callmethod(num54, "-", 1, partcv, params);
// compilenode returning diff60
  *var_b = diff60;
  if (diff60 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 31
  setline(31);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_c = undefined;
// compilenode returning none
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 32
  setline(32);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  int op_slot_left_61 = gc_frame_newslot(*var_b);
  Object num62 = alloc_Float64(4);
// compilenode returning num62
  int op_slot_right_61 = gc_frame_newslot(num62);
  params[0] = num62;
  partcv[0] = 1;
  Object prod64 = callmethod(*var_b, "*", 1, partcv, params);
// compilenode returning prod64
  *var_c = prod64;
  if (prod64 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 34
  setline(34);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool67 = alloc_Boolean(1);
// compilenode returning bool67
  int op_slot_left_66 = gc_frame_newslot(bool67);
  Object bool68 = alloc_Boolean(0);
// compilenode returning bool68
  int op_slot_right_66 = gc_frame_newslot(bool68);
  params[0] = bool68;
  partcv[0] = 1;
  Object opresult70 = callmethod(bool67, "||", 1, partcv, params);
// compilenode returning opresult70
  *var_d = opresult70;
  if (opresult70 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 34
  setline(34);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe71 = gc_frame_new();
  Object block72 = alloc_Block(NULL, NULL, "lig/test", 34);
  gc_frame_newslot(block72);
  block_savedest(block72);
  Object closure73 = createclosure(1, "_apply");
setclosureframe(closure73, stackframe);
  addtoclosure(closure73, selfslot);
  struct UserObject *uo73 = (struct UserObject*)block72;
  uo73->data[0] = (Object)closure73;
  Method *meth_meth_lig_47_test__apply73 = addmethod2pos(block72, "_apply", &meth_lig_47_test__apply73, 0);
int argcv_meth_lig_47_test__apply73[] = {0};
meth_meth_lig_47_test__apply73->type = alloc_MethodType(1, argcv_meth_lig_47_test__apply73);
  meth_meth_lig_47_test__apply73->definitionModule = modulename;
  meth_meth_lig_47_test__apply73->definitionLine = 76;
// compilenode returning block72
  gc_frame_newslot(block72);
  Object bool76 = alloc_Boolean(1);
// compilenode returning bool76
  params[0] = block72;
  partcv[0] = 1;
  Object call77 = callmethod(bool76, "orElse",
    1, partcv, params);
  gc_frame_end(callframe71);
// compilenode returning call77
  *var_d = call77;
  if (call77 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 35
  setline(35);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_c
  int op_slot_left_80 = gc_frame_newslot(*var_c);
  Object num81 = alloc_Float64(10);
// compilenode returning num81
  int op_slot_right_80 = gc_frame_newslot(num81);
  params[0] = num81;
  partcv[0] = 1;
  Object opresult83 = callmethod(*var_c, ">", 1, partcv, params);
// compilenode returning opresult83
  Object if79 = none;
  if (istrue(opresult83)) {
// Begin line 37
  setline(37);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 36
  setline(36);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_c
  int op_slot_left_84 = gc_frame_newslot(*var_c);
  Object num85 = alloc_Float64(10);
// compilenode returning num85
  int op_slot_right_84 = gc_frame_newslot(num85);
  params[0] = num85;
  partcv[0] = 1;
  Object diff87 = callmethod(*var_c, "-", 1, partcv, params);
// compilenode returning diff87
  *var_c = diff87;
  if (diff87 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if79 = none;
  } else {
  }
// compilenode returning if79
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 38
  setline(38);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_c
  int op_slot_left_89 = gc_frame_newslot(*var_c);
  Object num91 = alloc_Float64(60);
// compilenode returning num91
  int op_slot_left_90 = gc_frame_newslot(num91);
// compilenode returning *var_a
  int op_slot_right_90 = gc_frame_newslot(*var_a);
  params[0] = *var_a;
  partcv[0] = 1;
  Object quotient93 = callmethod(num91, "/", 1, partcv, params);
// compilenode returning quotient93
  int op_slot_right_89 = gc_frame_newslot(quotient93);
  params[0] = quotient93;
  partcv[0] = 1;
  Object prod95 = callmethod(*var_c, "*", 1, partcv, params);
// compilenode returning prod95
  return prod95;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_test_multiLine96(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(3, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "multiLine");
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
  Object *var_a = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "a");
  Object *var_b = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "b");
// Begin line 42
  setline(42);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num97 = alloc_Float64(1);
// compilenode returning num97
  *var_a = num97;
  if (num97 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 43
  setline(43);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num98 = alloc_Float64(2);
// compilenode returning num98
  *var_b = num98;
  if (num98 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 44
  setline(44);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  int op_slot_left_101 = gc_frame_newslot(*var_a);
// compilenode returning *var_b
  int op_slot_right_101 = gc_frame_newslot(*var_b);
  params[0] = *var_b;
  partcv[0] = 1;
  Object sum103 = callmethod(*var_a, "+", 1, partcv, params);
// compilenode returning sum103
  int op_slot_left_100 = gc_frame_newslot(sum103);
  Object num104 = alloc_Float64(3);
// compilenode returning num104
  int op_slot_right_100 = gc_frame_newslot(num104);
  params[0] = num104;
  partcv[0] = 1;
  Object opresult106 = callmethod(sum103, "==", 1, partcv, params);
// compilenode returning opresult106
  Object if99 = none;
  if (istrue(opresult106)) {
// Begin line 45
  setline(45);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit107 == NULL) {
    strlit107 = alloc_String("multi-line okay");
    gc_root(strlit107);
  }
// compilenode returning strlit107
  params[0] = strlit107;
  Object call108 = gracelib_print(NULL, 1,  params);
// compilenode returning call108
    gc_frame_newslot(call108);
    if99 = call108;
  } else {
// Begin line 47
  setline(47);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit109 == NULL) {
    strlit109 = alloc_String("multi-line FAIL");
    gc_root(strlit109);
  }
// compilenode returning strlit109
  params[0] = strlit109;
  Object call110 = gracelib_print(NULL, 1,  params);
// compilenode returning call110
    gc_frame_newslot(call110);
    if99 = call110;
  }
// compilenode returning if99
  gc_frame_end(frame);
  return if99;
}
Object meth_lig_47_test__apply152(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object self = *(getfromclosure(closure, 0));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object bool153 = alloc_Boolean(0);
// compilenode returning bool153
  gc_frame_end(frame);
  return bool153;
}
Object meth_lig_47_test_main111(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 7, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(12, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "main");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_recur = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_inlinedVar_6 = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "inlinedVar_6");
  Object *var_inlinedVar_7 = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "inlinedVar_7");
  Object *var_foo = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "foo");
  Object *var_inlinedVar_0 = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "inlinedVar_0");
  Object *var_inlinedVar_2 = &(stackframe->slots[5]);
  setframeelementname(stackframe, 5, "inlinedVar_2");
  Object *var_inlinedVar_3 = &(stackframe->slots[6]);
  setframeelementname(stackframe, 6, "inlinedVar_3");
  Object *var_inlinedVar_4 = &(stackframe->slots[7]);
  setframeelementname(stackframe, 7, "inlinedVar_4");
  Object *var_inlinedVar_5 = &(stackframe->slots[8]);
  setframeelementname(stackframe, 8, "inlinedVar_5");
  Object *var_a = &(stackframe->slots[9]);
  setframeelementname(stackframe, 9, "a");
  Object *var_inlinedVar_1 = &(stackframe->slots[10]);
  setframeelementname(stackframe, 10, "inlinedVar_1");
  Object *var_b = &(stackframe->slots[11]);
  setframeelementname(stackframe, 11, "b");
// Begin line 52
  setline(52);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe112 = gc_frame_new();
  Object num113 = alloc_Float64(4);
// compilenode returning num113
  gc_frame_newslot(num113);
  params[0] = num113;
  partcv[0] = 1;
  Object call114 = callmethodflags(self, "recurse", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe112);
// compilenode returning call114
// Begin line 53
  setline(53);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_recur
  int op_slot_left_116 = gc_frame_newslot(*var_recur);
  Object num117 = alloc_Float64(10);
// compilenode returning num117
  int op_slot_right_116 = gc_frame_newslot(num117);
  params[0] = num117;
  partcv[0] = 1;
  Object opresult119 = callmethod(*var_recur, "==", 1, partcv, params);
// compilenode returning opresult119
  Object if115 = none;
  if (istrue(opresult119)) {
// Begin line 54
  setline(54);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit120 == NULL) {
    strlit120 = alloc_String("recursive okay");
    gc_root(strlit120);
  }
// compilenode returning strlit120
  params[0] = strlit120;
  Object call121 = gracelib_print(NULL, 1,  params);
// compilenode returning call121
    gc_frame_newslot(call121);
    if115 = call121;
  } else {
// Begin line 56
  setline(56);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit122 == NULL) {
    strlit122 = alloc_String("recursive FAIL");
    gc_root(strlit122);
  }
// compilenode returning strlit122
  params[0] = strlit122;
  Object call123 = gracelib_print(NULL, 1,  params);
// compilenode returning call123
    gc_frame_newslot(call123);
    if115 = call123;
  }
// compilenode returning if115
// Begin line 42
  setline(42);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num124 = alloc_Float64(1);
// compilenode returning num124
  *var_inlinedVar_6 = num124;
  if (num124 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 43
  setline(43);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num125 = alloc_Float64(2);
// compilenode returning num125
  *var_inlinedVar_7 = num125;
  if (num125 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 44
  setline(44);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 42
  setline(42);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num129 = alloc_Float64(1);
// compilenode returning num129
  int op_slot_left_128 = gc_frame_newslot(num129);
// Begin line 43
  setline(43);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num130 = alloc_Float64(2);
// compilenode returning num130
  int op_slot_right_128 = gc_frame_newslot(num130);
  params[0] = num130;
  partcv[0] = 1;
  Object sum132 = callmethod(num129, "+", 1, partcv, params);
// compilenode returning sum132
  int op_slot_left_127 = gc_frame_newslot(sum132);
// Begin line 44
  setline(44);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num133 = alloc_Float64(3);
// compilenode returning num133
  int op_slot_right_127 = gc_frame_newslot(num133);
  params[0] = num133;
  partcv[0] = 1;
  Object opresult135 = callmethod(sum132, "==", 1, partcv, params);
// compilenode returning opresult135
  Object if126 = none;
  if (istrue(opresult135)) {
// Begin line 45
  setline(45);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit136 == NULL) {
    strlit136 = alloc_String("multi-line okay");
    gc_root(strlit136);
  }
// compilenode returning strlit136
  params[0] = strlit136;
  Object call137 = gracelib_print(NULL, 1,  params);
// compilenode returning call137
    gc_frame_newslot(call137);
    if126 = call137;
  } else {
// Begin line 47
  setline(47);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit138 == NULL) {
    strlit138 = alloc_String("multi-line FAIL");
    gc_root(strlit138);
  }
// compilenode returning strlit138
  params[0] = strlit138;
  Object call139 = gracelib_print(NULL, 1,  params);
// compilenode returning call139
    gc_frame_newslot(call139);
    if126 = call139;
  }
// compilenode returning if126
// Begin line 61
  setline(61);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit140 == NULL) {
    strlit140 = alloc_String("name conflicts okay 2");
    gc_root(strlit140);
  }
// compilenode returning strlit140
  *var_foo = strlit140;
  if (strlit140 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit141 == NULL) {
    strlit141 = alloc_String("name conflicts okay 1");
    gc_root(strlit141);
  }
// compilenode returning strlit141
  *var_inlinedVar_0 = strlit141;
  if (strlit141 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit142 == NULL) {
    strlit142 = alloc_String("name conflicts okay 1");
    gc_root(strlit142);
  }
// compilenode returning strlit142
  params[0] = strlit142;
  Object call143 = gracelib_print(NULL, 1,  params);
// compilenode returning call143
// Begin line 63
  setline(63);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_foo
  params[0] = *var_foo;
  Object call144 = gracelib_print(NULL, 1,  params);
// compilenode returning call144
// Begin line 29
  setline(29);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num145 = alloc_Float64(30);
// compilenode returning num145
  *var_inlinedVar_2 = num145;
  if (num145 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num146 = alloc_Float64(3);
// compilenode returning num146
  *var_inlinedVar_3 = num146;
  if (num146 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 31
  setline(31);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_inlinedVar_4 = undefined;
// compilenode returning none
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num147 = alloc_Float64(12);
// compilenode returning num147
  *var_inlinedVar_4 = num147;
  if (num147 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool149 = alloc_Boolean(1);
// compilenode returning bool149
  *var_inlinedVar_5 = bool149;
  if (bool149 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 34
  setline(34);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe150 = gc_frame_new();
  Object block151 = alloc_Block(NULL, NULL, "lig/test", 34);
  gc_frame_newslot(block151);
  block_savedest(block151);
  Object closure152 = createclosure(1, "_apply");
setclosureframe(closure152, stackframe);
  addtoclosure(closure152, selfslot);
  struct UserObject *uo152 = (struct UserObject*)block151;
  uo152->data[0] = (Object)closure152;
  Method *meth_meth_lig_47_test__apply152 = addmethod2pos(block151, "_apply", &meth_lig_47_test__apply152, 0);
int argcv_meth_lig_47_test__apply152[] = {0};
meth_meth_lig_47_test__apply152->type = alloc_MethodType(1, argcv_meth_lig_47_test__apply152);
  meth_meth_lig_47_test__apply152->definitionModule = modulename;
  meth_meth_lig_47_test__apply152->definitionLine = 76;
// compilenode returning block151
  gc_frame_newslot(block151);
  Object bool155 = alloc_Boolean(1);
// compilenode returning bool155
  params[0] = block151;
  partcv[0] = 1;
  Object call156 = callmethod(bool155, "orElse",
    1, partcv, params);
  gc_frame_end(callframe150);
// compilenode returning call156
  *var_inlinedVar_5 = call156;
  if (call156 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 35
  setline(35);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool159 = alloc_Boolean(1);
// compilenode returning bool159
  Object if158 = none;
  if (istrue(bool159)) {
// Begin line 37
  setline(37);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num160 = alloc_Float64(2);
// compilenode returning num160
  *var_inlinedVar_4 = num160;
  if (num160 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if158 = none;
  } else {
  }
// compilenode returning if158
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_4
  int op_slot_left_162 = gc_frame_newslot(*var_inlinedVar_4);
// Begin line 38
  setline(38);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num164 = alloc_Float64(60);
// compilenode returning num164
  int op_slot_left_163 = gc_frame_newslot(num164);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num165 = alloc_Float64(30);
// compilenode returning num165
  int op_slot_right_163 = gc_frame_newslot(num165);
  params[0] = num165;
  partcv[0] = 1;
  Object quotient167 = callmethod(num164, "/", 1, partcv, params);
// compilenode returning quotient167
  int op_slot_right_162 = gc_frame_newslot(quotient167);
  params[0] = quotient167;
  partcv[0] = 1;
  Object prod169 = callmethod(*var_inlinedVar_4, "*", 1, partcv, params);
// compilenode returning prod169
// Begin line 67
  setline(67);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num170 = alloc_Float64(5);
// compilenode returning num170
  *var_a = num170;
  if (num170 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 68
  setline(68);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  int op_slot_left_172 = gc_frame_newslot(*var_a);
  Object num173 = alloc_Float64(3);
// compilenode returning num173
  int op_slot_right_172 = gc_frame_newslot(num173);
  params[0] = num173;
  partcv[0] = 1;
  Object sum175 = callmethod(*var_a, "+", 1, partcv, params);
// compilenode returning sum175
  int op_slot_left_171 = gc_frame_newslot(sum175);
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num176 = alloc_Float64(2);
// compilenode returning num176
  int op_slot_right_171 = gc_frame_newslot(num176);
  params[0] = num176;
  partcv[0] = 1;
  Object diff178 = callmethod(sum175, "-", 1, partcv, params);
// compilenode returning diff178
  *var_inlinedVar_1 = diff178;
  if (diff178 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 68
  setline(68);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_179 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num180 = alloc_Float64(7);
// compilenode returning num180
  int op_slot_right_179 = gc_frame_newslot(num180);
  params[0] = num180;
  partcv[0] = 1;
  Object sum182 = callmethod(*var_inlinedVar_1, "+", 1, partcv, params);
// compilenode returning sum182
  *var_b = sum182;
  if (sum182 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 69
  setline(69);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  int op_slot_left_184 = gc_frame_newslot(*var_b);
  Object num185 = alloc_Float64(13);
// compilenode returning num185
  int op_slot_right_184 = gc_frame_newslot(num185);
  params[0] = num185;
  partcv[0] = 1;
  Object opresult187 = callmethod(*var_b, "==", 1, partcv, params);
// compilenode returning opresult187
  Object if183 = none;
  if (istrue(opresult187)) {
// Begin line 70
  setline(70);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit188 == NULL) {
    strlit188 = alloc_String("constantProp_Test");
    gc_root(strlit188);
  }
// compilenode returning strlit188
  params[0] = strlit188;
  Object call189 = gracelib_print(NULL, 1,  params);
// compilenode returning call189
    gc_frame_newslot(call189);
    if183 = call189;
  } else {
// Begin line 72
  setline(72);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit190 == NULL) {
    strlit190 = alloc_String("constantProp_Test FAIL");
    gc_root(strlit190);
  }
// compilenode returning strlit190
  params[0] = strlit190;
  Object call191 = gracelib_print(NULL, 1,  params);
// compilenode returning call191
    gc_frame_newslot(call191);
    if183 = call191;
  }
// compilenode returning if183
  gc_frame_end(frame);
  return if183;
}
Object meth_lig_47_test_orig195(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 8, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "orig");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_orig = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_orig
  gc_frame_end(frame);
  return *var_orig;
}
Object meth_lig_47_test_orig_58__61_196(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 9, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "orig:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_orig = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var__var_assign_tmp = &(stackframe->slots[0]);
  *var__var_assign_tmp = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var__var_assign_tmp
  *var_orig = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_test_recur199(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 10, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "recur");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_recur = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_recur
  gc_frame_end(frame);
  return *var_recur;
}
Object meth_lig_47_test_recur_58__61_200(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 11, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "recur:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_recur = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var__var_assign_tmp = &(stackframe->slots[0]);
  *var__var_assign_tmp = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var__var_assign_tmp
  *var_recur = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object module_lig_47_test_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(13, 13);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/test>");
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
  struct StackFrameObject *stackframe = alloc_StackFrame(13, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[1];
  int partcv[1];
  Object *var_orig = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "orig");
  Object *var_recur = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "recur");
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = emptyclosure;
  Method *meth_meth_lig_47_test_inline0 = addmethod2pos(self, "inline", &meth_lig_47_test_inline0, 1);
int argcv_meth_lig_47_test_inline0[] = {0};
meth_meth_lig_47_test_inline0->type = alloc_MethodType(1, argcv_meth_lig_47_test_inline0);
  meth_meth_lig_47_test_inline0->definitionModule = modulename;
  meth_meth_lig_47_test_inline0->definitionLine = 3;
// compilenode returning 
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[2] = emptyclosure;
  Method *meth_meth_lig_47_test_namingConflict1 = addmethod2pos(self, "namingConflict", &meth_lig_47_test_namingConflict1, 2);
int argcv_meth_lig_47_test_namingConflict1[] = {0};
meth_meth_lig_47_test_namingConflict1->type = alloc_MethodType(1, argcv_meth_lig_47_test_namingConflict1);
  meth_meth_lig_47_test_namingConflict1->definitionModule = modulename;
  meth_meth_lig_47_test_namingConflict1->definitionLine = 5;
// compilenode returning 
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure4 = createclosure(2, "recurse");
setclosureframe(closure4, stackframe);
  addtoclosure(closure4, var_orig);
  addtoclosure(closure4, var_recur);
  struct UserObject *uo4 = (struct UserObject*)self;
  uo4->data[3] = (Object)closure4;
  Method *meth_meth_lig_47_test_recurse4 = addmethod2pos(self, "recurse", &meth_lig_47_test_recurse4, 3);
int argcv_meth_lig_47_test_recurse4[] = {1};
meth_meth_lig_47_test_recurse4->type = alloc_MethodType(1, argcv_meth_lig_47_test_recurse4);
  meth_meth_lig_47_test_recurse4->definitionModule = modulename;
  meth_meth_lig_47_test_recurse4->definitionLine = 11;
// compilenode returning 
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo38 = (struct UserObject*)self;
  uo38->data[4] = emptyclosure;
  Method *meth_meth_lig_47_test_constantProp238 = addmethod2pos(self, "constantProp2", &meth_lig_47_test_constantProp238, 4);
int argcv_meth_lig_47_test_constantProp238[] = {1};
meth_meth_lig_47_test_constantProp238->type = alloc_MethodType(1, argcv_meth_lig_47_test_constantProp238);
  meth_meth_lig_47_test_constantProp238->definitionModule = modulename;
  meth_meth_lig_47_test_constantProp238->definitionLine = 23;
// compilenode returning 
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo47 = (struct UserObject*)self;
  uo47->data[5] = emptyclosure;
  Method *meth_meth_lig_47_test_constantProp147 = addmethod2pos(self, "constantProp1", &meth_lig_47_test_constantProp147, 5);
int argcv_meth_lig_47_test_constantProp147[] = {0};
meth_meth_lig_47_test_constantProp147->type = alloc_MethodType(1, argcv_meth_lig_47_test_constantProp147);
  meth_meth_lig_47_test_constantProp147->definitionModule = modulename;
  meth_meth_lig_47_test_constantProp147->definitionLine = 28;
// compilenode returning 
// Begin line 41
  setline(41);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo96 = (struct UserObject*)self;
  uo96->data[6] = emptyclosure;
  Method *meth_meth_lig_47_test_multiLine96 = addmethod2pos(self, "multiLine", &meth_lig_47_test_multiLine96, 6);
int argcv_meth_lig_47_test_multiLine96[] = {0};
meth_meth_lig_47_test_multiLine96->type = alloc_MethodType(1, argcv_meth_lig_47_test_multiLine96);
  meth_meth_lig_47_test_multiLine96->definitionModule = modulename;
  meth_meth_lig_47_test_multiLine96->definitionLine = 41;
// compilenode returning 
// Begin line 51
  setline(51);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure111 = createclosure(1, "main");
setclosureframe(closure111, stackframe);
  addtoclosure(closure111, var_recur);
  struct UserObject *uo111 = (struct UserObject*)self;
  uo111->data[7] = (Object)closure111;
  Method *meth_meth_lig_47_test_main111 = addmethod2pos(self, "main", &meth_lig_47_test_main111, 7);
int argcv_meth_lig_47_test_main111[] = {0};
meth_meth_lig_47_test_main111->type = alloc_MethodType(1, argcv_meth_lig_47_test_main111);
  meth_meth_lig_47_test_main111->definitionModule = modulename;
  meth_meth_lig_47_test_main111->definitionLine = 51;
// compilenode returning 
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe192 = gc_frame_new();
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num193 = alloc_Float64(1);
// compilenode returning num193
  partcv[0] = 0;
  Object call194 = callmethod(num193, "prefix-",
    1, partcv, params);
  gc_frame_end(callframe192);
// compilenode returning call194
  *var_orig = call194;
  if (call194 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure195 = createclosure(1, "orig");
setclosureframe(closure195, stackframe);
  addtoclosure(closure195, var_orig);
  struct UserObject *uo195 = (struct UserObject*)self;
  uo195->data[8] = (Object)closure195;
  Method *meth_meth_lig_47_test_orig195 = addmethod2pos(self, "orig", &meth_lig_47_test_orig195, 8);
int argcv_meth_lig_47_test_orig195[] = {0};
meth_meth_lig_47_test_orig195->type = alloc_MethodType(1, argcv_meth_lig_47_test_orig195);
  meth_meth_lig_47_test_orig195->definitionModule = modulename;
  meth_meth_lig_47_test_orig195->definitionLine = 76;
// compilenode returning 
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure196 = createclosure(1, "orig:=");
setclosureframe(closure196, stackframe);
  addtoclosure(closure196, var_orig);
  struct UserObject *uo196 = (struct UserObject*)self;
  uo196->data[9] = (Object)closure196;
  Method *meth_meth_lig_47_test_orig_58__61_196 = addmethod2pos(self, "orig:=", &meth_lig_47_test_orig_58__61_196, 9);
int argcv_meth_lig_47_test_orig_58__61_196[] = {1};
meth_meth_lig_47_test_orig_58__61_196->type = alloc_MethodType(1, argcv_meth_lig_47_test_orig_58__61_196);
  meth_meth_lig_47_test_orig_58__61_196->definitionModule = modulename;
  meth_meth_lig_47_test_orig_58__61_196->definitionLine = 76;
// compilenode returning 
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num198 = alloc_Float64(0);
// compilenode returning num198
  *var_recur = num198;
  if (num198 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure199 = createclosure(1, "recur");
setclosureframe(closure199, stackframe);
  addtoclosure(closure199, var_recur);
  struct UserObject *uo199 = (struct UserObject*)self;
  uo199->data[10] = (Object)closure199;
  Method *meth_meth_lig_47_test_recur199 = addmethod2pos(self, "recur", &meth_lig_47_test_recur199, 10);
int argcv_meth_lig_47_test_recur199[] = {0};
meth_meth_lig_47_test_recur199->type = alloc_MethodType(1, argcv_meth_lig_47_test_recur199);
  meth_meth_lig_47_test_recur199->definitionModule = modulename;
  meth_meth_lig_47_test_recur199->definitionLine = 76;
// compilenode returning 
// Begin line 76
  setline(76);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure200 = createclosure(1, "recur:=");
setclosureframe(closure200, stackframe);
  addtoclosure(closure200, var_recur);
  struct UserObject *uo200 = (struct UserObject*)self;
  uo200->data[11] = (Object)closure200;
  Method *meth_meth_lig_47_test_recur_58__61_200 = addmethod2pos(self, "recur:=", &meth_lig_47_test_recur_58__61_200, 11);
int argcv_meth_lig_47_test_recur_58__61_200[] = {1};
meth_meth_lig_47_test_recur_58__61_200->type = alloc_MethodType(1, argcv_meth_lig_47_test_recur_58__61_200);
  meth_meth_lig_47_test_recur_58__61_200->definitionModule = modulename;
  meth_meth_lig_47_test_recur_58__61_200->definitionLine = 76;
// compilenode returning 
// compilenode returning none
  int callframe202 = gc_frame_new();
  partcv[0] = 0;
  Object call203 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe202);
// compilenode returning call203
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
  module_lig_47_test_init();
  gracelib_stats();
  return 0;
}
