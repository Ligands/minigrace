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
static const char modulename[] = "lig/nqueens";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "import \"sys\" as sys",
  "def N : Number = 9",
  "var b := 1..N",
  "var s := 0;",
  "method inline{}",
  "method unsafe(y) is inline {",
  "    var x := b[y+1]",
  "    for(1..y) do { i->",
  "        var t := b[(y - i)+1]",
  "        if((t == x) ||",
  "            (t == (x - i)) ||",
  "            (t == (x + i))) then {",
  "            return true",
  "        }",
  "    }",
  "    false",
  "}",
  "var avg := 0",
  "method main(n){",
  "    var time := sys.cputime",
  "    var y := 0",
  "    b[1] := -1",
  "    while{y >= 0} do {",
  "        b[y+1] := b[y+1] + 1",
  "        var safe := unsafe(y)",
  "        while{(b[y+1] < N) && safe} do {",
  "            b[y+1] := b[y+1] + 1",
  "            safe := unsafe(y)",
  "        }",
  "        if(b[y+1] < N) then {",
  "            if(y < (N-1)) then {",
  "                y := y + 1",
  "                b[y+1] := -1;",
  "            }",
  "        } else {",
  "            y := y - 1",
  "        }",
  "    }",
  "    var tt:=(sys.cputime - time)",
  "    avg := avg + tt",
  "    print(\"Run {n}: {tt}s\")",
  "}",
  "for(1..15) do { i ->",
  "    main(i)",
  "}",
  "print(\"average : {avg/15}s\")",
  NULL
};
static Object strlit261;
static Object strlit264;
static Object strlit269;
Object module_sys;
Object module_sys_init();
static Object strlit304;
static Object strlit311;
Object meth_lig_47_nqueens_inline0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
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
Object meth_lig_47_nqueens__apply13(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  Object *var_y = getfromclosure(closure, 1);
  Object *var_inlinedVar_0 = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
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
  Object *var_inlinedVar_1 = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "inlinedVar_1");
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_15 = gc_frame_newslot(*var_y);
// compilenode returning *var_i
  int op_slot_right_15 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object diff17 = callmethod(*var_y, "-", 1, partcv, params);
// compilenode returning diff17
  int op_slot_left_14 = gc_frame_newslot(diff17);
  Object num18 = alloc_Float64(1);
// compilenode returning num18
  int op_slot_right_14 = gc_frame_newslot(num18);
  params[0] = num18;
  partcv[0] = 1;
  Object sum20 = callmethod(diff17, "+", 1, partcv, params);
// compilenode returning sum20
  params[0] = sum20;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres21 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres21
  *var_inlinedVar_1 = idxres21;
  if (idxres21 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_25 = gc_frame_newslot(*var_inlinedVar_1);
// compilenode returning *var_inlinedVar_0
  int op_slot_right_25 = gc_frame_newslot(*var_inlinedVar_0);
  params[0] = *var_inlinedVar_0;
  partcv[0] = 1;
  Object opresult27 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult27
  int op_slot_left_24 = gc_frame_newslot(opresult27);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_28 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_0
  int op_slot_left_29 = gc_frame_newslot(*var_inlinedVar_0);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_i
  int op_slot_right_29 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object diff31 = callmethod(*var_inlinedVar_0, "-", 1, partcv, params);
// compilenode returning diff31
  int op_slot_right_28 = gc_frame_newslot(diff31);
  params[0] = diff31;
  partcv[0] = 1;
  Object opresult33 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult33
  int op_slot_right_24 = gc_frame_newslot(opresult33);
  params[0] = opresult33;
  partcv[0] = 1;
  Object opresult35 = callmethod(opresult27, "||", 1, partcv, params);
// compilenode returning opresult35
  int op_slot_left_23 = gc_frame_newslot(opresult35);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_36 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_0
  int op_slot_left_37 = gc_frame_newslot(*var_inlinedVar_0);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_i
  int op_slot_right_37 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object sum39 = callmethod(*var_inlinedVar_0, "+", 1, partcv, params);
// compilenode returning sum39
  int op_slot_right_36 = gc_frame_newslot(sum39);
  params[0] = sum39;
  partcv[0] = 1;
  Object opresult41 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult41
  int op_slot_right_23 = gc_frame_newslot(opresult41);
  params[0] = opresult41;
  partcv[0] = 1;
  Object opresult43 = callmethod(opresult35, "||", 1, partcv, params);
// compilenode returning opresult43
  Object if22 = none;
  if (istrue(opresult43)) {
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool44 = alloc_Boolean(1);
// compilenode returning bool44
  block_return(realself, bool44);
// compilenode returning undefined
    gc_frame_newslot(undefined);
    if22 = undefined;
  } else {
  }
// compilenode returning if22
  gc_frame_end(frame);
  return if22;
}
Object meth_lig_47_nqueens_unsafe1(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 2, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "unsafe");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_b = getfromclosure(closure, 0);
  Object *var_inlinedVar_0 = getfromclosure(closure, 1);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_y = &(stackframe->slots[0]);
  *var_y = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_x = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "x");
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_2 = gc_frame_newslot(*var_y);
  Object num3 = alloc_Float64(1);
// compilenode returning num3
  int op_slot_right_2 = gc_frame_newslot(num3);
  params[0] = num3;
  partcv[0] = 1;
  Object sum5 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum5
  params[0] = sum5;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres6 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres6
  *var_x = idxres6;
  if (idxres6 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe7 = gc_frame_new();
  Object num9 = alloc_Float64(1);
// compilenode returning num9
  int op_slot_left_8 = gc_frame_newslot(num9);
// compilenode returning *var_y
  int op_slot_right_8 = gc_frame_newslot(*var_y);
  params[0] = *var_y;
  partcv[0] = 1;
  Object opresult11 = callmethod(num9, "..", 1, partcv, params);
// compilenode returning opresult11
  gc_frame_newslot(opresult11);
  Object block12 = alloc_Block(NULL, NULL, "lig/nqueens", 8);
  gc_frame_newslot(block12);
  block_savedest(block12);
  Object closure13 = createclosure(4, "_apply");
setclosureframe(closure13, stackframe);
  addtoclosure(closure13, var_b);
  addtoclosure(closure13, var_y);
  addtoclosure(closure13, var_inlinedVar_0);
  addtoclosure(closure13, selfslot);
  struct UserObject *uo13 = (struct UserObject*)block12;
  uo13->data[0] = (Object)closure13;
  Method *meth_meth_lig_47_nqueens__apply13 = addmethod2pos(block12, "_apply", &meth_lig_47_nqueens__apply13, 0);
int argcv_meth_lig_47_nqueens__apply13[] = {1};
meth_meth_lig_47_nqueens__apply13->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply13);
  meth_meth_lig_47_nqueens__apply13->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply13->definitionLine = 46;
// compilenode returning block12
  gc_frame_newslot(block12);
  params[0] = opresult11;
  params[1] = block12;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call46 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe7);
// compilenode returning call46
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool47 = alloc_Boolean(0);
// compilenode returning bool47
  gc_frame_end(frame);
  return bool47;
}
Object meth_lig_47_nqueens__apply60(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_y = getfromclosure(closure, 0);
  Object self = *(getfromclosure(closure, 1));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var_y
  int op_slot_left_61 = gc_frame_newslot(*var_y);
  Object num62 = alloc_Float64(0);
// compilenode returning num62
  int op_slot_right_61 = gc_frame_newslot(num62);
  params[0] = num62;
  partcv[0] = 1;
  Object opresult64 = callmethod(*var_y, ">=", 1, partcv, params);
// compilenode returning opresult64
  gc_frame_end(frame);
  return opresult64;
}
Object meth_lig_47_nqueens__apply94(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  Object *var_y = getfromclosure(closure, 1);
  Object *var_inlinedVar_0 = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
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
  Object *var_inlinedVar_1 = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "inlinedVar_1");
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_96 = gc_frame_newslot(*var_y);
// compilenode returning *var_i
  int op_slot_right_96 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object diff98 = callmethod(*var_y, "-", 1, partcv, params);
// compilenode returning diff98
  int op_slot_left_95 = gc_frame_newslot(diff98);
  Object num99 = alloc_Float64(1);
// compilenode returning num99
  int op_slot_right_95 = gc_frame_newslot(num99);
  params[0] = num99;
  partcv[0] = 1;
  Object sum101 = callmethod(diff98, "+", 1, partcv, params);
// compilenode returning sum101
  params[0] = sum101;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres102 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres102
  *var_inlinedVar_1 = idxres102;
  if (idxres102 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_106 = gc_frame_newslot(*var_inlinedVar_1);
// compilenode returning *var_inlinedVar_0
  int op_slot_right_106 = gc_frame_newslot(*var_inlinedVar_0);
  params[0] = *var_inlinedVar_0;
  partcv[0] = 1;
  Object opresult108 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult108
  int op_slot_left_105 = gc_frame_newslot(opresult108);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_109 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_0
  int op_slot_left_110 = gc_frame_newslot(*var_inlinedVar_0);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_i
  int op_slot_right_110 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object diff112 = callmethod(*var_inlinedVar_0, "-", 1, partcv, params);
// compilenode returning diff112
  int op_slot_right_109 = gc_frame_newslot(diff112);
  params[0] = diff112;
  partcv[0] = 1;
  Object opresult114 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult114
  int op_slot_right_105 = gc_frame_newslot(opresult114);
  params[0] = opresult114;
  partcv[0] = 1;
  Object opresult116 = callmethod(opresult108, "||", 1, partcv, params);
// compilenode returning opresult116
  int op_slot_left_104 = gc_frame_newslot(opresult116);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_117 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_0
  int op_slot_left_118 = gc_frame_newslot(*var_inlinedVar_0);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_i
  int op_slot_right_118 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object sum120 = callmethod(*var_inlinedVar_0, "+", 1, partcv, params);
// compilenode returning sum120
  int op_slot_right_117 = gc_frame_newslot(sum120);
  params[0] = sum120;
  partcv[0] = 1;
  Object opresult122 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult122
  int op_slot_right_104 = gc_frame_newslot(opresult122);
  params[0] = opresult122;
  partcv[0] = 1;
  Object opresult124 = callmethod(opresult116, "||", 1, partcv, params);
// compilenode returning opresult124
  Object if103 = none;
  if (istrue(opresult124)) {
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool125 = alloc_Boolean(1);
// compilenode returning bool125
  block_return(realself, bool125);
// compilenode returning undefined
    gc_frame_newslot(undefined);
    if103 = undefined;
  } else {
  }
// compilenode returning if103
  gc_frame_end(frame);
  return if103;
}
Object meth_lig_47_nqueens__apply131(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  Object *var_y = getfromclosure(closure, 1);
  Object *var_N = getfromclosure(closure, 2);
  Object *var_safe = getfromclosure(closure, 3);
  Object self = *(getfromclosure(closure, 4));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_134 = gc_frame_newslot(*var_y);
  Object num135 = alloc_Float64(1);
// compilenode returning num135
  int op_slot_right_134 = gc_frame_newslot(num135);
  params[0] = num135;
  partcv[0] = 1;
  Object sum137 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum137
  params[0] = sum137;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres138 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres138
  int op_slot_left_133 = gc_frame_newslot(idxres138);
// compilenode returning *var_N
  int op_slot_right_133 = gc_frame_newslot(*var_N);
  params[0] = *var_N;
  partcv[0] = 1;
  Object opresult140 = callmethod(idxres138, "<", 1, partcv, params);
// compilenode returning opresult140
  int op_slot_left_132 = gc_frame_newslot(opresult140);
// compilenode returning *var_safe
  int op_slot_right_132 = gc_frame_newslot(*var_safe);
  params[0] = *var_safe;
  partcv[0] = 1;
  Object opresult142 = callmethod(opresult140, "&&", 1, partcv, params);
// compilenode returning opresult142
  gc_frame_end(frame);
  return opresult142;
}
Object meth_lig_47_nqueens__apply172(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  Object *var_y = getfromclosure(closure, 1);
  Object *var_inlinedVar_0 = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
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
  Object *var_inlinedVar_1 = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "inlinedVar_1");
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_174 = gc_frame_newslot(*var_y);
// compilenode returning *var_i
  int op_slot_right_174 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object diff176 = callmethod(*var_y, "-", 1, partcv, params);
// compilenode returning diff176
  int op_slot_left_173 = gc_frame_newslot(diff176);
  Object num177 = alloc_Float64(1);
// compilenode returning num177
  int op_slot_right_173 = gc_frame_newslot(num177);
  params[0] = num177;
  partcv[0] = 1;
  Object sum179 = callmethod(diff176, "+", 1, partcv, params);
// compilenode returning sum179
  params[0] = sum179;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres180 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres180
  *var_inlinedVar_1 = idxres180;
  if (idxres180 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_184 = gc_frame_newslot(*var_inlinedVar_1);
// compilenode returning *var_inlinedVar_0
  int op_slot_right_184 = gc_frame_newslot(*var_inlinedVar_0);
  params[0] = *var_inlinedVar_0;
  partcv[0] = 1;
  Object opresult186 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult186
  int op_slot_left_183 = gc_frame_newslot(opresult186);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_187 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_0
  int op_slot_left_188 = gc_frame_newslot(*var_inlinedVar_0);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_i
  int op_slot_right_188 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object diff190 = callmethod(*var_inlinedVar_0, "-", 1, partcv, params);
// compilenode returning diff190
  int op_slot_right_187 = gc_frame_newslot(diff190);
  params[0] = diff190;
  partcv[0] = 1;
  Object opresult192 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult192
  int op_slot_right_183 = gc_frame_newslot(opresult192);
  params[0] = opresult192;
  partcv[0] = 1;
  Object opresult194 = callmethod(opresult186, "||", 1, partcv, params);
// compilenode returning opresult194
  int op_slot_left_182 = gc_frame_newslot(opresult194);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_1
  int op_slot_left_195 = gc_frame_newslot(*var_inlinedVar_1);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_0
  int op_slot_left_196 = gc_frame_newslot(*var_inlinedVar_0);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_i
  int op_slot_right_196 = gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object sum198 = callmethod(*var_inlinedVar_0, "+", 1, partcv, params);
// compilenode returning sum198
  int op_slot_right_195 = gc_frame_newslot(sum198);
  params[0] = sum198;
  partcv[0] = 1;
  Object opresult200 = callmethod(*var_inlinedVar_1, "==", 1, partcv, params);
// compilenode returning opresult200
  int op_slot_right_182 = gc_frame_newslot(opresult200);
  params[0] = opresult200;
  partcv[0] = 1;
  Object opresult202 = callmethod(opresult194, "||", 1, partcv, params);
// compilenode returning opresult202
  Object if181 = none;
  if (istrue(opresult202)) {
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool203 = alloc_Boolean(1);
// compilenode returning bool203
  block_return(realself, bool203);
// compilenode returning undefined
    gc_frame_newslot(undefined);
    if181 = undefined;
  } else {
  }
// compilenode returning if181
  gc_frame_end(frame);
  return if181;
}
Object meth_lig_47_nqueens__apply145(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_y = getfromclosure(closure, 0);
  Object *var_b = getfromclosure(closure, 1);
  Object *var_safe = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_inlinedVar_0 = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "inlinedVar_0");
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe146 = gc_frame_new();
// Begin line 27
  setline(27);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_left_147 = gc_frame_newslot(*var_y);
  Object num148 = alloc_Float64(1);
// compilenode returning num148
  int op_slot_right_147 = gc_frame_newslot(num148);
  params[0] = num148;
  partcv[0] = 1;
  Object sum150 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum150
  gc_frame_newslot(sum150);
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 27
  setline(27);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_152 = gc_frame_newslot(*var_y);
  Object num153 = alloc_Float64(1);
// compilenode returning num153
  int op_slot_right_152 = gc_frame_newslot(num153);
  params[0] = num153;
  partcv[0] = 1;
  Object sum155 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum155
  params[0] = sum155;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres156 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres156
  int op_slot_left_151 = gc_frame_newslot(idxres156);
  Object num157 = alloc_Float64(1);
// compilenode returning num157
  int op_slot_right_151 = gc_frame_newslot(num157);
  params[0] = num157;
  partcv[0] = 1;
  Object sum159 = callmethod(idxres156, "+", 1, partcv, params);
// compilenode returning sum159
  gc_frame_newslot(sum159);
// compilenode returning *var_b
  params[0] = sum150;
  params[1] = sum159;
  partcv[0] = 2;
  Object call160 = callmethod(*var_b, "[]:=",
    1, partcv, params);
  gc_frame_end(callframe146);
// compilenode returning call160
// compilenode returning none
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_161 = gc_frame_newslot(*var_y);
  Object num162 = alloc_Float64(1);
// compilenode returning num162
  int op_slot_right_161 = gc_frame_newslot(num162);
  params[0] = num162;
  partcv[0] = 1;
  Object sum164 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum164
  params[0] = sum164;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres165 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres165
  *var_inlinedVar_0 = idxres165;
  if (idxres165 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe166 = gc_frame_new();
  Object num168 = alloc_Float64(1);
// compilenode returning num168
  int op_slot_left_167 = gc_frame_newslot(num168);
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_right_167 = gc_frame_newslot(*var_y);
  params[0] = *var_y;
  partcv[0] = 1;
  Object opresult170 = callmethod(num168, "..", 1, partcv, params);
// compilenode returning opresult170
  gc_frame_newslot(opresult170);
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object block171 = alloc_Block(NULL, NULL, "lig/nqueens", 8);
  gc_frame_newslot(block171);
  block_savedest(block171);
  Object closure172 = createclosure(4, "_apply");
setclosureframe(closure172, stackframe);
  addtoclosure(closure172, var_b);
  addtoclosure(closure172, var_y);
  addtoclosure(closure172, var_inlinedVar_0);
  addtoclosure(closure172, selfslot);
  struct UserObject *uo172 = (struct UserObject*)block171;
  uo172->data[0] = (Object)closure172;
  Method *meth_meth_lig_47_nqueens__apply172 = addmethod2pos(block171, "_apply", &meth_lig_47_nqueens__apply172, 0);
int argcv_meth_lig_47_nqueens__apply172[] = {1};
meth_meth_lig_47_nqueens__apply172->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply172);
  meth_meth_lig_47_nqueens__apply172->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply172->definitionLine = 20;
// compilenode returning block171
  gc_frame_newslot(block171);
  params[0] = opresult170;
  params[1] = block171;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call205 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe166);
// compilenode returning call205
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool206 = alloc_Boolean(0);
// compilenode returning bool206
  *var_safe = bool206;
  if (bool206 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_nqueens__apply67(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_y = getfromclosure(closure, 0);
  Object *var_b = getfromclosure(closure, 1);
  Object *var_N = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_inlinedVar_0 = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "inlinedVar_0");
  Object *var_safe = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "safe");
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe68 = gc_frame_new();
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_left_69 = gc_frame_newslot(*var_y);
  Object num70 = alloc_Float64(1);
// compilenode returning num70
  int op_slot_right_69 = gc_frame_newslot(num70);
  params[0] = num70;
  partcv[0] = 1;
  Object sum72 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum72
  gc_frame_newslot(sum72);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_74 = gc_frame_newslot(*var_y);
  Object num75 = alloc_Float64(1);
// compilenode returning num75
  int op_slot_right_74 = gc_frame_newslot(num75);
  params[0] = num75;
  partcv[0] = 1;
  Object sum77 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum77
  params[0] = sum77;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres78 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres78
  int op_slot_left_73 = gc_frame_newslot(idxres78);
  Object num79 = alloc_Float64(1);
// compilenode returning num79
  int op_slot_right_73 = gc_frame_newslot(num79);
  params[0] = num79;
  partcv[0] = 1;
  Object sum81 = callmethod(idxres78, "+", 1, partcv, params);
// compilenode returning sum81
  gc_frame_newslot(sum81);
// compilenode returning *var_b
  params[0] = sum72;
  params[1] = sum81;
  partcv[0] = 2;
  Object call82 = callmethod(*var_b, "[]:=",
    1, partcv, params);
  gc_frame_end(callframe68);
// compilenode returning call82
// compilenode returning none
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_83 = gc_frame_newslot(*var_y);
  Object num84 = alloc_Float64(1);
// compilenode returning num84
  int op_slot_right_83 = gc_frame_newslot(num84);
  params[0] = num84;
  partcv[0] = 1;
  Object sum86 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum86
  params[0] = sum86;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres87 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres87
  *var_inlinedVar_0 = idxres87;
  if (idxres87 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe88 = gc_frame_new();
  Object num90 = alloc_Float64(1);
// compilenode returning num90
  int op_slot_left_89 = gc_frame_newslot(num90);
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_right_89 = gc_frame_newslot(*var_y);
  params[0] = *var_y;
  partcv[0] = 1;
  Object opresult92 = callmethod(num90, "..", 1, partcv, params);
// compilenode returning opresult92
  gc_frame_newslot(opresult92);
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object block93 = alloc_Block(NULL, NULL, "lig/nqueens", 8);
  gc_frame_newslot(block93);
  block_savedest(block93);
  Object closure94 = createclosure(4, "_apply");
setclosureframe(closure94, stackframe);
  addtoclosure(closure94, var_b);
  addtoclosure(closure94, var_y);
  addtoclosure(closure94, var_inlinedVar_0);
  addtoclosure(closure94, selfslot);
  struct UserObject *uo94 = (struct UserObject*)block93;
  uo94->data[0] = (Object)closure94;
  Method *meth_meth_lig_47_nqueens__apply94 = addmethod2pos(block93, "_apply", &meth_lig_47_nqueens__apply94, 0);
int argcv_meth_lig_47_nqueens__apply94[] = {1};
meth_meth_lig_47_nqueens__apply94->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply94);
  meth_meth_lig_47_nqueens__apply94->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply94->definitionLine = 20;
// compilenode returning block93
  gc_frame_newslot(block93);
  params[0] = opresult92;
  params[1] = block93;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call127 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe88);
// compilenode returning call127
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool128 = alloc_Boolean(0);
// compilenode returning bool128
  *var_safe = bool128;
  if (bool128 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 26
  setline(26);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe129 = gc_frame_new();
  Object block130 = alloc_Block(NULL, NULL, "lig/nqueens", 26);
  gc_frame_newslot(block130);
  block_savedest(block130);
  Object closure131 = createclosure(5, "_apply");
setclosureframe(closure131, stackframe);
  addtoclosure(closure131, var_b);
  addtoclosure(closure131, var_y);
  addtoclosure(closure131, var_N);
  addtoclosure(closure131, var_safe);
  addtoclosure(closure131, selfslot);
  struct UserObject *uo131 = (struct UserObject*)block130;
  uo131->data[0] = (Object)closure131;
  Method *meth_meth_lig_47_nqueens__apply131 = addmethod2pos(block130, "_apply", &meth_lig_47_nqueens__apply131, 0);
int argcv_meth_lig_47_nqueens__apply131[] = {0};
meth_meth_lig_47_nqueens__apply131->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply131);
  meth_meth_lig_47_nqueens__apply131->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply131->definitionLine = 20;
// compilenode returning block130
  gc_frame_newslot(block130);
  Object block144 = alloc_Block(NULL, NULL, "lig/nqueens", 26);
  gc_frame_newslot(block144);
  block_savedest(block144);
  Object closure145 = createclosure(4, "_apply");
setclosureframe(closure145, stackframe);
  addtoclosure(closure145, var_y);
  addtoclosure(closure145, var_b);
  addtoclosure(closure145, var_safe);
  addtoclosure(closure145, selfslot);
  struct UserObject *uo145 = (struct UserObject*)block144;
  uo145->data[0] = (Object)closure145;
  Method *meth_meth_lig_47_nqueens__apply145 = addmethod2pos(block144, "_apply", &meth_lig_47_nqueens__apply145, 0);
int argcv_meth_lig_47_nqueens__apply145[] = {0};
meth_meth_lig_47_nqueens__apply145->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply145);
  meth_meth_lig_47_nqueens__apply145->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply145->definitionLine = 20;
// compilenode returning block144
  gc_frame_newslot(block144);
  params[0] = block130;
  params[1] = block144;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call209 = callmethodflags(prelude, "while()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe129);
// compilenode returning call209
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
// compilenode returning *var_y
  int op_slot_left_212 = gc_frame_newslot(*var_y);
  Object num213 = alloc_Float64(1);
// compilenode returning num213
  int op_slot_right_212 = gc_frame_newslot(num213);
  params[0] = num213;
  partcv[0] = 1;
  Object sum215 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum215
  params[0] = sum215;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres216 = callmethod(*var_b, "[]", 1, partcv, params);
// compilenode returning idxres216
  int op_slot_left_211 = gc_frame_newslot(idxres216);
// compilenode returning *var_N
  int op_slot_right_211 = gc_frame_newslot(*var_N);
  params[0] = *var_N;
  partcv[0] = 1;
  Object opresult218 = callmethod(idxres216, "<", 1, partcv, params);
// compilenode returning opresult218
  Object if210 = none;
  if (istrue(opresult218)) {
// Begin line 31
  setline(31);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_left_220 = gc_frame_newslot(*var_y);
// compilenode returning *var_N
  int op_slot_left_221 = gc_frame_newslot(*var_N);
  Object num222 = alloc_Float64(1);
// compilenode returning num222
  int op_slot_right_221 = gc_frame_newslot(num222);
  params[0] = num222;
  partcv[0] = 1;
  Object diff224 = callmethod(*var_N, "-", 1, partcv, params);
// compilenode returning diff224
  int op_slot_right_220 = gc_frame_newslot(diff224);
  params[0] = diff224;
  partcv[0] = 1;
  Object opresult226 = callmethod(*var_y, "<", 1, partcv, params);
// compilenode returning opresult226
  Object if219 = none;
  if (istrue(opresult226)) {
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 32
  setline(32);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_left_227 = gc_frame_newslot(*var_y);
  Object num228 = alloc_Float64(1);
// compilenode returning num228
  int op_slot_right_227 = gc_frame_newslot(num228);
  params[0] = num228;
  partcv[0] = 1;
  Object sum230 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum230
  *var_y = sum230;
  if (sum230 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe232 = gc_frame_new();
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_left_233 = gc_frame_newslot(*var_y);
  Object num234 = alloc_Float64(1);
// compilenode returning num234
  int op_slot_right_233 = gc_frame_newslot(num234);
  params[0] = num234;
  partcv[0] = 1;
  Object sum236 = callmethod(*var_y, "+", 1, partcv, params);
// compilenode returning sum236
  gc_frame_newslot(sum236);
  int callframe237 = gc_frame_new();
  Object num238 = alloc_Float64(1);
// compilenode returning num238
  partcv[0] = 0;
  Object call239 = callmethod(num238, "prefix-",
    1, partcv, params);
  gc_frame_end(callframe237);
// compilenode returning call239
  gc_frame_newslot(call239);
// compilenode returning *var_b
  params[0] = sum236;
  params[1] = call239;
  partcv[0] = 2;
  Object call240 = callmethod(*var_b, "[]:=",
    1, partcv, params);
  gc_frame_end(callframe232);
// compilenode returning call240
// compilenode returning none
    gc_frame_newslot(none);
    if219 = none;
  } else {
  }
// compilenode returning if219
    gc_frame_newslot(if219);
    if210 = if219;
  } else {
// Begin line 37
  setline(37);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 36
  setline(36);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_y
  int op_slot_left_241 = gc_frame_newslot(*var_y);
  Object num242 = alloc_Float64(1);
// compilenode returning num242
  int op_slot_right_241 = gc_frame_newslot(num242);
  params[0] = num242;
  partcv[0] = 1;
  Object diff244 = callmethod(*var_y, "-", 1, partcv, params);
// compilenode returning diff244
  *var_y = diff244;
  if (diff244 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if210 = none;
  }
// compilenode returning if210
  gc_frame_end(frame);
  return if210;
}
Object meth_lig_47_nqueens_main48(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 3, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(5, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "main");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_sys = getfromclosure(closure, 0);
  Object *var_b = getfromclosure(closure, 1);
  Object *var_N = getfromclosure(closure, 2);
  Object *var_avg = getfromclosure(closure, 3);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_n = &(stackframe->slots[0]);
  *var_n = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_time = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "time");
  Object *var_y = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "y");
  Object *var_tt = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "tt");
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe49 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call50 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe49);
// compilenode returning call50
// compilenode returning call50
  *var_time = call50;
  if (call50 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 21
  setline(21);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num51 = alloc_Float64(0);
// compilenode returning num51
  *var_y = num51;
  if (num51 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe52 = gc_frame_new();
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num53 = alloc_Float64(1);
// compilenode returning num53
  gc_frame_newslot(num53);
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe54 = gc_frame_new();
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num55 = alloc_Float64(1);
// compilenode returning num55
  partcv[0] = 0;
  Object call56 = callmethod(num55, "prefix-",
    1, partcv, params);
  gc_frame_end(callframe54);
// compilenode returning call56
  gc_frame_newslot(call56);
// compilenode returning *var_b
  params[0] = num53;
  params[1] = call56;
  partcv[0] = 2;
  Object call57 = callmethod(*var_b, "[]:=",
    1, partcv, params);
  gc_frame_end(callframe52);
// compilenode returning call57
// compilenode returning none
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe58 = gc_frame_new();
  Object block59 = alloc_Block(NULL, NULL, "lig/nqueens", 23);
  gc_frame_newslot(block59);
  block_savedest(block59);
  Object closure60 = createclosure(2, "_apply");
setclosureframe(closure60, stackframe);
  addtoclosure(closure60, var_y);
  addtoclosure(closure60, selfslot);
  struct UserObject *uo60 = (struct UserObject*)block59;
  uo60->data[0] = (Object)closure60;
  Method *meth_meth_lig_47_nqueens__apply60 = addmethod2pos(block59, "_apply", &meth_lig_47_nqueens__apply60, 0);
int argcv_meth_lig_47_nqueens__apply60[] = {0};
meth_meth_lig_47_nqueens__apply60->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply60);
  meth_meth_lig_47_nqueens__apply60->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply60->definitionLine = 20;
// compilenode returning block59
  gc_frame_newslot(block59);
  Object block66 = alloc_Block(NULL, NULL, "lig/nqueens", 23);
  gc_frame_newslot(block66);
  block_savedest(block66);
  Object closure67 = createclosure(4, "_apply");
setclosureframe(closure67, stackframe);
  addtoclosure(closure67, var_y);
  addtoclosure(closure67, var_b);
  addtoclosure(closure67, var_N);
  addtoclosure(closure67, selfslot);
  struct UserObject *uo67 = (struct UserObject*)block66;
  uo67->data[0] = (Object)closure67;
  Method *meth_meth_lig_47_nqueens__apply67 = addmethod2pos(block66, "_apply", &meth_lig_47_nqueens__apply67, 0);
int argcv_meth_lig_47_nqueens__apply67[] = {0};
meth_meth_lig_47_nqueens__apply67->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply67);
  meth_meth_lig_47_nqueens__apply67->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply67->definitionLine = 20;
// compilenode returning block66
  gc_frame_newslot(block66);
  params[0] = block59;
  params[1] = block66;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call247 = callmethodflags(prelude, "while()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe58);
// compilenode returning call247
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe249 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call250 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe249);
// compilenode returning call250
// compilenode returning call250
  int op_slot_left_248 = gc_frame_newslot(call250);
// compilenode returning *var_time
  int op_slot_right_248 = gc_frame_newslot(*var_time);
  params[0] = *var_time;
  partcv[0] = 1;
  Object diff252 = callmethod(call250, "-", 1, partcv, params);
// compilenode returning diff252
  *var_tt = diff252;
  if (diff252 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 41
  setline(41);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 40
  setline(40);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_avg
  int op_slot_left_253 = gc_frame_newslot(*var_avg);
// compilenode returning *var_tt
  int op_slot_right_253 = gc_frame_newslot(*var_tt);
  params[0] = *var_tt;
  partcv[0] = 1;
  Object sum255 = callmethod(*var_avg, "+", 1, partcv, params);
// compilenode returning sum255
  *var_avg = sum255;
  if (sum255 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 41
  setline(41);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit261 == NULL) {
    strlit261 = alloc_String("Run ");
    gc_root(strlit261);
  }
// compilenode returning strlit261
  int op_slot_left_260 = gc_frame_newslot(strlit261);
// compilenode returning *var_n
  int op_slot_right_260 = gc_frame_newslot(*var_n);
  params[0] = *var_n;
  partcv[0] = 1;
  Object opresult263 = callmethod(strlit261, "++", 1, partcv, params);
// compilenode returning opresult263
  int op_slot_left_259 = gc_frame_newslot(opresult263);
  if (strlit264 == NULL) {
    strlit264 = alloc_String(": ");
    gc_root(strlit264);
  }
// compilenode returning strlit264
  int op_slot_right_259 = gc_frame_newslot(strlit264);
  params[0] = strlit264;
  partcv[0] = 1;
  Object opresult266 = callmethod(opresult263, "++", 1, partcv, params);
// compilenode returning opresult266
  int op_slot_left_258 = gc_frame_newslot(opresult266);
// compilenode returning *var_tt
  int op_slot_right_258 = gc_frame_newslot(*var_tt);
  params[0] = *var_tt;
  partcv[0] = 1;
  Object opresult268 = callmethod(opresult266, "++", 1, partcv, params);
// compilenode returning opresult268
  int op_slot_left_257 = gc_frame_newslot(opresult268);
  if (strlit269 == NULL) {
    strlit269 = alloc_String("s");
    gc_root(strlit269);
  }
// compilenode returning strlit269
  int op_slot_right_257 = gc_frame_newslot(strlit269);
  params[0] = strlit269;
  partcv[0] = 1;
  Object opresult271 = callmethod(opresult268, "++", 1, partcv, params);
// compilenode returning opresult271
  params[0] = opresult271;
  Object call272 = gracelib_print(NULL, 1,  params);
// compilenode returning call272
  gc_frame_end(frame);
  return call272;
}
Object meth_lig_47_nqueens_N274(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 4, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "N");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_N = getfromclosure(closure, 0);
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
// compilenode returning *var_N
  gc_frame_end(frame);
  return *var_N;
}
Object meth_lig_47_nqueens_b279(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 5, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "b");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  gc_frame_end(frame);
  return *var_b;
}
Object meth_lig_47_nqueens_b_58__61_280(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 6, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "b:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
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
  *var_b = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_nqueens_s283(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 7, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "s");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_s = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_s
  gc_frame_end(frame);
  return *var_s;
}
Object meth_lig_47_nqueens_s_58__61_284(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 8, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "s:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_s = getfromclosure(closure, 0);
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
  *var_s = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_nqueens_avg287(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 9, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "avg");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_avg = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 18
  setline(18);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_avg
  gc_frame_end(frame);
  return *var_avg;
}
Object meth_lig_47_nqueens_avg_58__61_288(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 10, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "avg:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_avg = getfromclosure(closure, 0);
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
  *var_avg = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_nqueens__apply297(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
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
  Object self = *(getfromclosure(closure, 0));
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
// Begin line 44
  setline(44);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe298 = gc_frame_new();
// compilenode returning *var_i
  gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object call299 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe298);
// compilenode returning call299
  gc_frame_end(frame);
  return call299;
}
Object module_lig_47_nqueens_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(12, 12);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/nqueens>");
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
  struct StackFrameObject *stackframe = alloc_StackFrame(12, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[2];
  int partcv[2];
Object *var_sys = alloc_var();
  Object *var_N = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "N");
  Object *var_b = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "b");
  Object *var_s = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "s");
  Object *var_avg = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "avg");
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = emptyclosure;
  Method *meth_meth_lig_47_nqueens_inline0 = addmethod2pos(self, "inline", &meth_lig_47_nqueens_inline0, 1);
int argcv_meth_lig_47_nqueens_inline0[] = {0};
meth_meth_lig_47_nqueens_inline0->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_inline0);
  meth_meth_lig_47_nqueens_inline0->definitionModule = modulename;
  meth_meth_lig_47_nqueens_inline0->definitionLine = 5;
// compilenode returning 
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure1 = createclosure(2, "unsafe");
setclosureframe(closure1, stackframe);
  addtoclosure(closure1, var_b);
  addtoclosure(closure1, var_inlinedVar_0);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[2] = (Object)closure1;
  Method *meth_meth_lig_47_nqueens_unsafe1 = addmethod2pos(self, "unsafe", &meth_lig_47_nqueens_unsafe1, 2);
int argcv_meth_lig_47_nqueens_unsafe1[] = {1};
meth_meth_lig_47_nqueens_unsafe1->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_unsafe1);
  meth_meth_lig_47_nqueens_unsafe1->definitionModule = modulename;
  meth_meth_lig_47_nqueens_unsafe1->definitionLine = 6;
// compilenode returning 
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure48 = createclosure(4, "main");
setclosureframe(closure48, stackframe);
  addtoclosure(closure48, var_sys);
  addtoclosure(closure48, var_b);
  addtoclosure(closure48, var_N);
  addtoclosure(closure48, var_avg);
  struct UserObject *uo48 = (struct UserObject*)self;
  uo48->data[3] = (Object)closure48;
  Method *meth_meth_lig_47_nqueens_main48 = addmethod2pos(self, "main", &meth_lig_47_nqueens_main48, 3);
int argcv_meth_lig_47_nqueens_main48[] = {1};
meth_meth_lig_47_nqueens_main48->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_main48);
  meth_meth_lig_47_nqueens_main48->definitionModule = modulename;
  meth_meth_lig_47_nqueens_main48->definitionLine = 19;
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
  Object num273 = alloc_Float64(9);
// compilenode returning num273
  *var_N = num273;
  if (num273 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure274 = createclosure(1, "N");
setclosureframe(closure274, stackframe);
  addtoclosure(closure274, var_N);
  struct UserObject *uo274 = (struct UserObject*)self;
  uo274->data[4] = (Object)closure274;
  Method *meth_meth_lig_47_nqueens_N274 = addmethod2pos(self, "N", &meth_lig_47_nqueens_N274, 4);
int argcv_meth_lig_47_nqueens_N274[] = {0};
meth_meth_lig_47_nqueens_N274->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_N274);
  meth_meth_lig_47_nqueens_N274->definitionModule = modulename;
  meth_meth_lig_47_nqueens_N274->definitionLine = 39;
// compilenode returning 
// compilenode returning none
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num276 = alloc_Float64(1);
// compilenode returning num276
  int op_slot_left_275 = gc_frame_newslot(num276);
// compilenode returning *var_N
  int op_slot_right_275 = gc_frame_newslot(*var_N);
  params[0] = *var_N;
  partcv[0] = 1;
  Object opresult278 = callmethod(num276, "..", 1, partcv, params);
// compilenode returning opresult278
  *var_b = opresult278;
  if (opresult278 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure279 = createclosure(1, "b");
setclosureframe(closure279, stackframe);
  addtoclosure(closure279, var_b);
  struct UserObject *uo279 = (struct UserObject*)self;
  uo279->data[5] = (Object)closure279;
  Method *meth_meth_lig_47_nqueens_b279 = addmethod2pos(self, "b", &meth_lig_47_nqueens_b279, 5);
int argcv_meth_lig_47_nqueens_b279[] = {0};
meth_meth_lig_47_nqueens_b279->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_b279);
  meth_meth_lig_47_nqueens_b279->definitionModule = modulename;
  meth_meth_lig_47_nqueens_b279->definitionLine = 39;
// compilenode returning 
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure280 = createclosure(1, "b:=");
setclosureframe(closure280, stackframe);
  addtoclosure(closure280, var_b);
  struct UserObject *uo280 = (struct UserObject*)self;
  uo280->data[6] = (Object)closure280;
  Method *meth_meth_lig_47_nqueens_b_58__61_280 = addmethod2pos(self, "b:=", &meth_lig_47_nqueens_b_58__61_280, 6);
int argcv_meth_lig_47_nqueens_b_58__61_280[] = {1};
meth_meth_lig_47_nqueens_b_58__61_280->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_b_58__61_280);
  meth_meth_lig_47_nqueens_b_58__61_280->definitionModule = modulename;
  meth_meth_lig_47_nqueens_b_58__61_280->definitionLine = 39;
// compilenode returning 
// compilenode returning none
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num282 = alloc_Float64(0);
// compilenode returning num282
  *var_s = num282;
  if (num282 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure283 = createclosure(1, "s");
setclosureframe(closure283, stackframe);
  addtoclosure(closure283, var_s);
  struct UserObject *uo283 = (struct UserObject*)self;
  uo283->data[7] = (Object)closure283;
  Method *meth_meth_lig_47_nqueens_s283 = addmethod2pos(self, "s", &meth_lig_47_nqueens_s283, 7);
int argcv_meth_lig_47_nqueens_s283[] = {0};
meth_meth_lig_47_nqueens_s283->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_s283);
  meth_meth_lig_47_nqueens_s283->definitionModule = modulename;
  meth_meth_lig_47_nqueens_s283->definitionLine = 39;
// compilenode returning 
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure284 = createclosure(1, "s:=");
setclosureframe(closure284, stackframe);
  addtoclosure(closure284, var_s);
  struct UserObject *uo284 = (struct UserObject*)self;
  uo284->data[8] = (Object)closure284;
  Method *meth_meth_lig_47_nqueens_s_58__61_284 = addmethod2pos(self, "s:=", &meth_lig_47_nqueens_s_58__61_284, 8);
int argcv_meth_lig_47_nqueens_s_58__61_284[] = {1};
meth_meth_lig_47_nqueens_s_58__61_284->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_s_58__61_284);
  meth_meth_lig_47_nqueens_s_58__61_284->definitionModule = modulename;
  meth_meth_lig_47_nqueens_s_58__61_284->definitionLine = 39;
// compilenode returning 
// compilenode returning none
// Begin line 18
  setline(18);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num286 = alloc_Float64(0);
// compilenode returning num286
  *var_avg = num286;
  if (num286 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure287 = createclosure(1, "avg");
setclosureframe(closure287, stackframe);
  addtoclosure(closure287, var_avg);
  struct UserObject *uo287 = (struct UserObject*)self;
  uo287->data[9] = (Object)closure287;
  Method *meth_meth_lig_47_nqueens_avg287 = addmethod2pos(self, "avg", &meth_lig_47_nqueens_avg287, 9);
int argcv_meth_lig_47_nqueens_avg287[] = {0};
meth_meth_lig_47_nqueens_avg287->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_avg287);
  meth_meth_lig_47_nqueens_avg287->definitionModule = modulename;
  meth_meth_lig_47_nqueens_avg287->definitionLine = 39;
// compilenode returning 
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure288 = createclosure(1, "avg:=");
setclosureframe(closure288, stackframe);
  addtoclosure(closure288, var_avg);
  struct UserObject *uo288 = (struct UserObject*)self;
  uo288->data[10] = (Object)closure288;
  Method *meth_meth_lig_47_nqueens_avg_58__61_288 = addmethod2pos(self, "avg:=", &meth_lig_47_nqueens_avg_58__61_288, 10);
int argcv_meth_lig_47_nqueens_avg_58__61_288[] = {1};
meth_meth_lig_47_nqueens_avg_58__61_288->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens_avg_58__61_288);
  meth_meth_lig_47_nqueens_avg_58__61_288->definitionModule = modulename;
  meth_meth_lig_47_nqueens_avg_58__61_288->definitionLine = 39;
// compilenode returning 
// compilenode returning none
// Begin line 43
  setline(43);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe290 = gc_frame_new();
  Object num292 = alloc_Float64(1);
// compilenode returning num292
  int op_slot_left_291 = gc_frame_newslot(num292);
  Object num293 = alloc_Float64(15);
// compilenode returning num293
  int op_slot_right_291 = gc_frame_newslot(num293);
  params[0] = num293;
  partcv[0] = 1;
  Object opresult295 = callmethod(num292, "..", 1, partcv, params);
// compilenode returning opresult295
  gc_frame_newslot(opresult295);
  Object block296 = alloc_Block(NULL, NULL, "lig/nqueens", 43);
  gc_frame_newslot(block296);
  block_savedest(block296);
  Object closure297 = createclosure(1, "_apply");
setclosureframe(closure297, stackframe);
  addtoclosure(closure297, selfslot);
  struct UserObject *uo297 = (struct UserObject*)block296;
  uo297->data[0] = (Object)closure297;
  Method *meth_meth_lig_47_nqueens__apply297 = addmethod2pos(block296, "_apply", &meth_lig_47_nqueens__apply297, 0);
int argcv_meth_lig_47_nqueens__apply297[] = {1};
meth_meth_lig_47_nqueens__apply297->type = alloc_MethodType(1, argcv_meth_lig_47_nqueens__apply297);
  meth_meth_lig_47_nqueens__apply297->definitionModule = modulename;
  meth_meth_lig_47_nqueens__apply297->definitionLine = 39;
// compilenode returning block296
  gc_frame_newslot(block296);
  params[0] = opresult295;
  params[1] = block296;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call301 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe290);
// compilenode returning call301
// Begin line 46
  setline(46);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit304 == NULL) {
    strlit304 = alloc_String("average : ");
    gc_root(strlit304);
  }
// compilenode returning strlit304
  int op_slot_left_303 = gc_frame_newslot(strlit304);
// compilenode returning *var_avg
  int op_slot_left_305 = gc_frame_newslot(*var_avg);
  Object num306 = alloc_Float64(15);
// compilenode returning num306
  int op_slot_right_305 = gc_frame_newslot(num306);
  params[0] = num306;
  partcv[0] = 1;
  Object quotient308 = callmethod(*var_avg, "/", 1, partcv, params);
// compilenode returning quotient308
  int op_slot_right_303 = gc_frame_newslot(quotient308);
  params[0] = quotient308;
  partcv[0] = 1;
  Object opresult310 = callmethod(strlit304, "++", 1, partcv, params);
// compilenode returning opresult310
  int op_slot_left_302 = gc_frame_newslot(opresult310);
  if (strlit311 == NULL) {
    strlit311 = alloc_String("s");
    gc_root(strlit311);
  }
// compilenode returning strlit311
  int op_slot_right_302 = gc_frame_newslot(strlit311);
  params[0] = strlit311;
  partcv[0] = 1;
  Object opresult313 = callmethod(opresult310, "++", 1, partcv, params);
// compilenode returning opresult313
  params[0] = opresult313;
  Object call314 = gracelib_print(NULL, 1,  params);
// compilenode returning call314
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
  module_lig_47_nqueens_init();
  gracelib_stats();
  return 0;
}
