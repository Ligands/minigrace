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
static const char modulename[] = "lig/alioth/binary-trees";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "import \"sys\" as sys",
  "def nil = object {}",
  "method item_check(ar){",
  "    def left = ar[1]",
  "    def item = ar[2]",
  "    def right = ar[3]",
  "    if(left == nil) then { return item }",
  "    item + (item_check(left) - item_check(right))",
  "}",
  "method bottom_up_tree(item, depth){",
  "    if(depth <= 0) then { return [nil, item, nil] }",
  "    var item_item := 2 * item",
  "    def d = depth - 1",
  "    [bottom_up_tree(item_item - 1, d), item, bottom_up_tree(item_item, d)]",
  "}",
  "method main(){",
  "    def max_depth:Number = 12    // 12 = default, 16 = slow, 8 = fast",
  "    def min_depth:Number = 4",
  "    var stretch_depth := max_depth + 1",
  "    var stretch_tree := bottom_up_tree(0, stretch_depth)",
  "    print(\"stretch tree of depth {stretch_depth}\\t check: {item_check(stretch_tree)}\")",
  "    stretch_tree := nil",
  "    var long_lived_tree := bottom_up_tree(0, max_depth)",
  "    var time := sys.cputime // timer start",
  "    var depth := min_depth",
  "    while{depth < (max_depth + 1)} do {",
  "        var iterations := 2^((max_depth - depth) + min_depth)",
  "        var check := 0",
  "        for(1..iterations) do { i->",
  "            var temp_tree := bottom_up_tree(i, depth)",
  "            check := check + item_check(temp_tree)",
  "            temp_tree := bottom_up_tree(-i, depth)",
  "            check := check + item_check(temp_tree)",
  "        }",
  "        print \"{iterations * 2}\\ttrees of depth {depth}\\t check: {check}\"",
  "        depth := depth + 2",
  "    }",
  "    print \"long lived tree of depth {max_depth}\\t check: {item_check(long_lived_tree)}\"",
  "    time := (sys.cputime - time) // timer end",
  "    if(time >= 2) then { print \" * (execution time = {time}s)\" }",
  "    else { print \" * (execution time = {time*1000}ms)\" }",
  "}",
  "main",
  NULL
};
Object reader_lig_47_alioth_47_binary_45_trees_outer_217(Object self, int nparams, int *argcv, Object* args, int flags) {
  struct UserObject *uo = (struct UserObject*)self;
  return uo->data[0];
}
static Object strlit59;
static Object strlit62;
static Object strlit69;
static Object strlit137;
static Object strlit144;
static Object strlit149;
static Object strlit154;
static Object strlit169;
static Object strlit172;
static Object strlit179;
static Object strlit196;
static Object strlit199;
static Object strlit205;
static Object strlit212;
Object module_sys;
Object module_sys_init();
static ClassData objclass216;
Object meth_lig_47_alioth_47_binary_45_trees_item_check0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 1, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(5, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "item_check");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_nil = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_ar = &(stackframe->slots[0]);
  *var_ar = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_left = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "left");
  Object *var_item = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "item");
  Object *var_right = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "right");
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_ar
  Object num1 = alloc_Float64(1);
// compilenode returning num1
  params[0] = num1;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres2 = callmethod(*var_ar, "[]", 1, partcv, params);
// compilenode returning idxres2
  *var_left = idxres2;
  if (idxres2 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_ar
  Object num3 = alloc_Float64(2);
// compilenode returning num3
  params[0] = num3;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres4 = callmethod(*var_ar, "[]", 1, partcv, params);
// compilenode returning idxres4
  *var_item = idxres4;
  if (idxres4 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_ar
  Object num5 = alloc_Float64(3);
// compilenode returning num5
  params[0] = num5;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres6 = callmethod(*var_ar, "[]", 1, partcv, params);
// compilenode returning idxres6
  *var_right = idxres6;
  if (idxres6 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_left
  int op_slot_left_8 = gc_frame_newslot(*var_left);
// compilenode returning *var_nil
  int op_slot_right_8 = gc_frame_newslot(*var_nil);
  params[0] = *var_nil;
  partcv[0] = 1;
  Object opresult10 = callmethod(*var_left, "==", 1, partcv, params);
// compilenode returning opresult10
  Object if7 = none;
  if (istrue(opresult10)) {
// compilenode returning *var_item
  return *var_item;
// compilenode returning undefined
    gc_frame_newslot(undefined);
    if7 = undefined;
  } else {
  }
// compilenode returning if7
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_item
  int op_slot_left_11 = gc_frame_newslot(*var_item);
  int callframe13 = gc_frame_new();
// compilenode returning *var_left
  gc_frame_newslot(*var_left);
  params[0] = *var_left;
  partcv[0] = 1;
  Object call14 = callmethodflags(self, "item_check", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe13);
// compilenode returning call14
  int op_slot_left_12 = gc_frame_newslot(call14);
  int callframe15 = gc_frame_new();
// compilenode returning *var_right
  gc_frame_newslot(*var_right);
  params[0] = *var_right;
  partcv[0] = 1;
  Object call16 = callmethodflags(self, "item_check", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe15);
// compilenode returning call16
  int op_slot_right_12 = gc_frame_newslot(call16);
  params[0] = call16;
  partcv[0] = 1;
  Object diff18 = callmethod(call14, "-", 1, partcv, params);
// compilenode returning diff18
  int op_slot_right_11 = gc_frame_newslot(diff18);
  params[0] = diff18;
  partcv[0] = 1;
  Object sum20 = callmethod(*var_item, "+", 1, partcv, params);
// compilenode returning sum20
  gc_frame_end(frame);
  return sum20;
}
Object meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 2, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(5, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "bottom_up_tree");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 2)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[1];
  Object *var_nil = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_item = &(stackframe->slots[0]);
  *var_item = args[curarg];
  curarg++;
  Object *var_depth = &(stackframe->slots[1]);
  *var_depth = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[2]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_item_item = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "item_item");
  Object *var_d = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "d");
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_depth
  int op_slot_left_23 = gc_frame_newslot(*var_depth);
  Object num24 = alloc_Float64(0);
// compilenode returning num24
  int op_slot_right_23 = gc_frame_newslot(num24);
  params[0] = num24;
  partcv[0] = 1;
  Object opresult26 = callmethod(*var_depth, "<=", 1, partcv, params);
// compilenode returning opresult26
  Object if22 = none;
  if (istrue(opresult26)) {
  Object array27 = alloc_List();
  gc_pause();
// compilenode returning *var_nil
  params[0] = *var_nil;
  partcv[0] = 1;
  callmethod(array27, "push", 1, partcv, params);
// compilenode returning *var_item
  params[0] = *var_item;
  partcv[0] = 1;
  callmethod(array27, "push", 1, partcv, params);
// compilenode returning *var_nil
  params[0] = *var_nil;
  partcv[0] = 1;
  callmethod(array27, "push", 1, partcv, params);
  gc_unpause();
// compilenode returning array27
  return array27;
// compilenode returning undefined
    gc_frame_newslot(undefined);
    if22 = undefined;
  } else {
  }
// compilenode returning if22
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num29 = alloc_Float64(2);
// compilenode returning num29
  int op_slot_left_28 = gc_frame_newslot(num29);
// compilenode returning *var_item
  int op_slot_right_28 = gc_frame_newslot(*var_item);
  params[0] = *var_item;
  partcv[0] = 1;
  Object prod31 = callmethod(num29, "*", 1, partcv, params);
// compilenode returning prod31
  *var_item_item = prod31;
  if (prod31 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_depth
  int op_slot_left_32 = gc_frame_newslot(*var_depth);
  Object num33 = alloc_Float64(1);
// compilenode returning num33
  int op_slot_right_32 = gc_frame_newslot(num33);
  params[0] = num33;
  partcv[0] = 1;
  Object diff35 = callmethod(*var_depth, "-", 1, partcv, params);
// compilenode returning diff35
  *var_d = diff35;
  if (diff35 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object array36 = alloc_List();
  gc_pause();
  int callframe37 = gc_frame_new();
// compilenode returning *var_item_item
  int op_slot_left_38 = gc_frame_newslot(*var_item_item);
  Object num39 = alloc_Float64(1);
// compilenode returning num39
  int op_slot_right_38 = gc_frame_newslot(num39);
  params[0] = num39;
  partcv[0] = 1;
  Object diff41 = callmethod(*var_item_item, "-", 1, partcv, params);
// compilenode returning diff41
  gc_frame_newslot(diff41);
// compilenode returning *var_d
  gc_frame_newslot(*var_d);
  params[0] = diff41;
  params[1] = *var_d;
  partcv[0] = 2;
  Object call42 = callmethodflags(self, "bottom_up_tree", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe37);
// compilenode returning call42
  params[0] = call42;
  partcv[0] = 1;
  callmethod(array36, "push", 1, partcv, params);
// compilenode returning *var_item
  params[0] = *var_item;
  partcv[0] = 1;
  callmethod(array36, "push", 1, partcv, params);
  int callframe43 = gc_frame_new();
// compilenode returning *var_item_item
  gc_frame_newslot(*var_item_item);
// compilenode returning *var_d
  gc_frame_newslot(*var_d);
  params[0] = *var_item_item;
  params[1] = *var_d;
  partcv[0] = 2;
  Object call44 = callmethodflags(self, "bottom_up_tree", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe43);
// compilenode returning call44
  params[0] = call44;
  partcv[0] = 1;
  callmethod(array36, "push", 1, partcv, params);
  gc_unpause();
// compilenode returning array36
  gc_frame_end(frame);
  return array36;
}
Object meth_lig_47_alioth_47_binary_45_trees__apply81(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_depth = getfromclosure(closure, 0);
  Object *var_max_depth = getfromclosure(closure, 1);
  Object self = *(getfromclosure(closure, 2));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var_depth
  int op_slot_left_82 = gc_frame_newslot(*var_depth);
// compilenode returning *var_max_depth
  int op_slot_left_83 = gc_frame_newslot(*var_max_depth);
  Object num84 = alloc_Float64(1);
// compilenode returning num84
  int op_slot_right_83 = gc_frame_newslot(num84);
  params[0] = num84;
  partcv[0] = 1;
  Object sum86 = callmethod(*var_max_depth, "+", 1, partcv, params);
// compilenode returning sum86
  int op_slot_right_82 = gc_frame_newslot(sum86);
  params[0] = sum86;
  partcv[0] = 1;
  Object opresult88 = callmethod(*var_depth, "<", 1, partcv, params);
// compilenode returning opresult88
  gc_frame_end(frame);
  return opresult88;
}
Object meth_lig_47_alioth_47_binary_45_trees__apply109(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[1];
  Object *var_depth = getfromclosure(closure, 0);
  Object *var_check = getfromclosure(closure, 1);
  Object self = *(getfromclosure(closure, 2));
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
  Object *var_temp_tree = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "temp_tree");
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe110 = gc_frame_new();
// compilenode returning *var_i
  gc_frame_newslot(*var_i);
// compilenode returning *var_depth
  gc_frame_newslot(*var_depth);
  params[0] = *var_i;
  params[1] = *var_depth;
  partcv[0] = 2;
  Object call111 = callmethodflags(self, "bottom_up_tree", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe110);
// compilenode returning call111
  *var_temp_tree = call111;
  if (call111 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 31
  setline(31);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_check
  int op_slot_left_112 = gc_frame_newslot(*var_check);
  int callframe113 = gc_frame_new();
// compilenode returning *var_temp_tree
  gc_frame_newslot(*var_temp_tree);
  params[0] = *var_temp_tree;
  partcv[0] = 1;
  Object call114 = callmethodflags(self, "item_check", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe113);
// compilenode returning call114
  int op_slot_right_112 = gc_frame_newslot(call114);
  params[0] = call114;
  partcv[0] = 1;
  Object sum116 = callmethod(*var_check, "+", 1, partcv, params);
// compilenode returning sum116
  *var_check = sum116;
  if (sum116 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 32
  setline(32);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe118 = gc_frame_new();
  int callframe119 = gc_frame_new();
// compilenode returning *var_i
  partcv[0] = 0;
  Object call120 = callmethod(*var_i, "prefix-",
    1, partcv, params);
  gc_frame_end(callframe119);
// compilenode returning call120
  gc_frame_newslot(call120);
// compilenode returning *var_depth
  gc_frame_newslot(*var_depth);
  params[0] = call120;
  params[1] = *var_depth;
  partcv[0] = 2;
  Object call121 = callmethodflags(self, "bottom_up_tree", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe118);
// compilenode returning call121
  *var_temp_tree = call121;
  if (call121 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_check
  int op_slot_left_123 = gc_frame_newslot(*var_check);
  int callframe124 = gc_frame_new();
// compilenode returning *var_temp_tree
  gc_frame_newslot(*var_temp_tree);
  params[0] = *var_temp_tree;
  partcv[0] = 1;
  Object call125 = callmethodflags(self, "item_check", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe124);
// compilenode returning call125
  int op_slot_right_123 = gc_frame_newslot(call125);
  params[0] = call125;
  partcv[0] = 1;
  Object sum127 = callmethod(*var_check, "+", 1, partcv, params);
// compilenode returning sum127
  *var_check = sum127;
  if (sum127 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_alioth_47_binary_45_trees__apply91(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_max_depth = getfromclosure(closure, 0);
  Object *var_depth = getfromclosure(closure, 1);
  Object *var_min_depth = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_iterations = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "iterations");
  Object *var_check = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "check");
// Begin line 27
  setline(27);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 27
  setline(27);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num93 = alloc_Float64(2);
// compilenode returning num93
  int op_slot_left_92 = gc_frame_newslot(num93);
// compilenode returning *var_max_depth
  int op_slot_left_95 = gc_frame_newslot(*var_max_depth);
// compilenode returning *var_depth
  int op_slot_right_95 = gc_frame_newslot(*var_depth);
  params[0] = *var_depth;
  partcv[0] = 1;
  Object diff97 = callmethod(*var_max_depth, "-", 1, partcv, params);
// compilenode returning diff97
  int op_slot_left_94 = gc_frame_newslot(diff97);
// compilenode returning *var_min_depth
  int op_slot_right_94 = gc_frame_newslot(*var_min_depth);
  params[0] = *var_min_depth;
  partcv[0] = 1;
  Object sum99 = callmethod(diff97, "+", 1, partcv, params);
// compilenode returning sum99
  int op_slot_right_92 = gc_frame_newslot(sum99);
  params[0] = sum99;
  partcv[0] = 1;
  Object opresult101 = callmethod(num93, "^", 1, partcv, params);
// compilenode returning opresult101
  *var_iterations = opresult101;
  if (opresult101 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num102 = alloc_Float64(0);
// compilenode returning num102
  *var_check = num102;
  if (num102 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 29
  setline(29);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe103 = gc_frame_new();
  Object num105 = alloc_Float64(1);
// compilenode returning num105
  int op_slot_left_104 = gc_frame_newslot(num105);
// compilenode returning *var_iterations
  int op_slot_right_104 = gc_frame_newslot(*var_iterations);
  params[0] = *var_iterations;
  partcv[0] = 1;
  Object opresult107 = callmethod(num105, "..", 1, partcv, params);
// compilenode returning opresult107
  gc_frame_newslot(opresult107);
  Object block108 = alloc_Block(NULL, NULL, "lig/alioth/binary-trees", 29);
  gc_frame_newslot(block108);
  block_savedest(block108);
  Object closure109 = createclosure(3, "_apply");
setclosureframe(closure109, stackframe);
  addtoclosure(closure109, var_depth);
  addtoclosure(closure109, var_check);
  addtoclosure(closure109, selfslot);
  struct UserObject *uo109 = (struct UserObject*)block108;
  uo109->data[0] = (Object)closure109;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees__apply109 = addmethod2pos(block108, "_apply", &meth_lig_47_alioth_47_binary_45_trees__apply109, 0);
int argcv_meth_lig_47_alioth_47_binary_45_trees__apply109[] = {1};
meth_meth_lig_47_alioth_47_binary_45_trees__apply109->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees__apply109);
  meth_meth_lig_47_alioth_47_binary_45_trees__apply109->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees__apply109->definitionLine = 24;
// compilenode returning block108
  gc_frame_newslot(block108);
  params[0] = opresult107;
  params[1] = block108;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call130 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe103);
// compilenode returning call130
// Begin line 35
  setline(35);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit137 == NULL) {
    strlit137 = alloc_String("");
    gc_root(strlit137);
  }
// compilenode returning strlit137
  int op_slot_left_136 = gc_frame_newslot(strlit137);
// compilenode returning *var_iterations
  int op_slot_left_138 = gc_frame_newslot(*var_iterations);
  Object num139 = alloc_Float64(2);
// compilenode returning num139
  int op_slot_right_138 = gc_frame_newslot(num139);
  params[0] = num139;
  partcv[0] = 1;
  Object prod141 = callmethod(*var_iterations, "*", 1, partcv, params);
// compilenode returning prod141
  int op_slot_right_136 = gc_frame_newslot(prod141);
  params[0] = prod141;
  partcv[0] = 1;
  Object opresult143 = callmethod(strlit137, "++", 1, partcv, params);
// compilenode returning opresult143
  int op_slot_left_135 = gc_frame_newslot(opresult143);
  if (strlit144 == NULL) {
    strlit144 = alloc_String("""\x09""trees of depth ");
    gc_root(strlit144);
  }
// compilenode returning strlit144
  int op_slot_right_135 = gc_frame_newslot(strlit144);
  params[0] = strlit144;
  partcv[0] = 1;
  Object opresult146 = callmethod(opresult143, "++", 1, partcv, params);
// compilenode returning opresult146
  int op_slot_left_134 = gc_frame_newslot(opresult146);
// compilenode returning *var_depth
  int op_slot_right_134 = gc_frame_newslot(*var_depth);
  params[0] = *var_depth;
  partcv[0] = 1;
  Object opresult148 = callmethod(opresult146, "++", 1, partcv, params);
// compilenode returning opresult148
  int op_slot_left_133 = gc_frame_newslot(opresult148);
  if (strlit149 == NULL) {
    strlit149 = alloc_String("""\x09"" check: ");
    gc_root(strlit149);
  }
// compilenode returning strlit149
  int op_slot_right_133 = gc_frame_newslot(strlit149);
  params[0] = strlit149;
  partcv[0] = 1;
  Object opresult151 = callmethod(opresult148, "++", 1, partcv, params);
// compilenode returning opresult151
  int op_slot_left_132 = gc_frame_newslot(opresult151);
// compilenode returning *var_check
  int op_slot_right_132 = gc_frame_newslot(*var_check);
  params[0] = *var_check;
  partcv[0] = 1;
  Object opresult153 = callmethod(opresult151, "++", 1, partcv, params);
// compilenode returning opresult153
  int op_slot_left_131 = gc_frame_newslot(opresult153);
  if (strlit154 == NULL) {
    strlit154 = alloc_String("");
    gc_root(strlit154);
  }
// compilenode returning strlit154
  int op_slot_right_131 = gc_frame_newslot(strlit154);
  params[0] = strlit154;
  partcv[0] = 1;
  Object opresult156 = callmethod(opresult153, "++", 1, partcv, params);
// compilenode returning opresult156
  params[0] = opresult156;
  Object call157 = gracelib_print(NULL, 1,  params);
// compilenode returning call157
// Begin line 37
  setline(37);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 36
  setline(36);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_depth
  int op_slot_left_158 = gc_frame_newslot(*var_depth);
  Object num159 = alloc_Float64(2);
// compilenode returning num159
  int op_slot_right_158 = gc_frame_newslot(num159);
  params[0] = num159;
  partcv[0] = 1;
  Object sum161 = callmethod(*var_depth, "+", 1, partcv, params);
// compilenode returning sum161
  *var_depth = sum161;
  if (sum161 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_alioth_47_binary_45_trees_main45(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 3, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(8, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "main");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_nil = getfromclosure(closure, 0);
  Object *var_sys = getfromclosure(closure, 1);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_max_depth = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "max_depth");
  Object *var_min_depth = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "min_depth");
  Object *var_stretch_depth = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "stretch_depth");
  Object *var_stretch_tree = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "stretch_tree");
  Object *var_long_lived_tree = &(stackframe->slots[5]);
  setframeelementname(stackframe, 5, "long_lived_tree");
  Object *var_time = &(stackframe->slots[6]);
  setframeelementname(stackframe, 6, "time");
  Object *var_depth = &(stackframe->slots[7]);
  setframeelementname(stackframe, 7, "depth");
// Begin line 17
  setline(17);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num46 = alloc_Float64(12);
// compilenode returning num46
  *var_max_depth = num46;
  if (num46 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 18
  setline(18);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num47 = alloc_Float64(4);
// compilenode returning num47
  *var_min_depth = num47;
  if (num47 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_max_depth
  int op_slot_left_48 = gc_frame_newslot(*var_max_depth);
  Object num49 = alloc_Float64(1);
// compilenode returning num49
  int op_slot_right_48 = gc_frame_newslot(num49);
  params[0] = num49;
  partcv[0] = 1;
  Object sum51 = callmethod(*var_max_depth, "+", 1, partcv, params);
// compilenode returning sum51
  *var_stretch_depth = sum51;
  if (sum51 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe52 = gc_frame_new();
  Object num53 = alloc_Float64(0);
// compilenode returning num53
  gc_frame_newslot(num53);
// compilenode returning *var_stretch_depth
  gc_frame_newslot(*var_stretch_depth);
  params[0] = num53;
  params[1] = *var_stretch_depth;
  partcv[0] = 2;
  Object call54 = callmethodflags(self, "bottom_up_tree", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe52);
// compilenode returning call54
  *var_stretch_tree = call54;
  if (call54 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 21
  setline(21);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit59 == NULL) {
    strlit59 = alloc_String("stretch tree of depth ");
    gc_root(strlit59);
  }
// compilenode returning strlit59
  int op_slot_left_58 = gc_frame_newslot(strlit59);
// compilenode returning *var_stretch_depth
  int op_slot_right_58 = gc_frame_newslot(*var_stretch_depth);
  params[0] = *var_stretch_depth;
  partcv[0] = 1;
  Object opresult61 = callmethod(strlit59, "++", 1, partcv, params);
// compilenode returning opresult61
  int op_slot_left_57 = gc_frame_newslot(opresult61);
  if (strlit62 == NULL) {
    strlit62 = alloc_String("""\x09"" check: ");
    gc_root(strlit62);
  }
// compilenode returning strlit62
  int op_slot_right_57 = gc_frame_newslot(strlit62);
  params[0] = strlit62;
  partcv[0] = 1;
  Object opresult64 = callmethod(opresult61, "++", 1, partcv, params);
// compilenode returning opresult64
  int op_slot_left_56 = gc_frame_newslot(opresult64);
  int callframe65 = gc_frame_new();
// compilenode returning *var_stretch_tree
  gc_frame_newslot(*var_stretch_tree);
  params[0] = *var_stretch_tree;
  partcv[0] = 1;
  Object call66 = callmethodflags(self, "item_check", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe65);
// compilenode returning call66
  int op_slot_right_56 = gc_frame_newslot(call66);
  params[0] = call66;
  partcv[0] = 1;
  Object opresult68 = callmethod(opresult64, "++", 1, partcv, params);
// compilenode returning opresult68
  int op_slot_left_55 = gc_frame_newslot(opresult68);
  if (strlit69 == NULL) {
    strlit69 = alloc_String("");
    gc_root(strlit69);
  }
// compilenode returning strlit69
  int op_slot_right_55 = gc_frame_newslot(strlit69);
  params[0] = strlit69;
  partcv[0] = 1;
  Object opresult71 = callmethod(opresult68, "++", 1, partcv, params);
// compilenode returning opresult71
  params[0] = opresult71;
  Object call72 = gracelib_print(NULL, 1,  params);
// compilenode returning call72
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_nil
  *var_stretch_tree = *var_nil;
  if (*var_nil == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe74 = gc_frame_new();
  Object num75 = alloc_Float64(0);
// compilenode returning num75
  gc_frame_newslot(num75);
// compilenode returning *var_max_depth
  gc_frame_newslot(*var_max_depth);
  params[0] = num75;
  params[1] = *var_max_depth;
  partcv[0] = 2;
  Object call76 = callmethodflags(self, "bottom_up_tree", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe74);
// compilenode returning call76
  *var_long_lived_tree = call76;
  if (call76 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe77 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call78 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe77);
// compilenode returning call78
// compilenode returning call78
  *var_time = call78;
  if (call78 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_min_depth
  *var_depth = *var_min_depth;
  if (*var_min_depth == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 26
  setline(26);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe79 = gc_frame_new();
  Object block80 = alloc_Block(NULL, NULL, "lig/alioth/binary-trees", 26);
  gc_frame_newslot(block80);
  block_savedest(block80);
  Object closure81 = createclosure(3, "_apply");
setclosureframe(closure81, stackframe);
  addtoclosure(closure81, var_depth);
  addtoclosure(closure81, var_max_depth);
  addtoclosure(closure81, selfslot);
  struct UserObject *uo81 = (struct UserObject*)block80;
  uo81->data[0] = (Object)closure81;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees__apply81 = addmethod2pos(block80, "_apply", &meth_lig_47_alioth_47_binary_45_trees__apply81, 0);
int argcv_meth_lig_47_alioth_47_binary_45_trees__apply81[] = {0};
meth_meth_lig_47_alioth_47_binary_45_trees__apply81->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees__apply81);
  meth_meth_lig_47_alioth_47_binary_45_trees__apply81->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees__apply81->definitionLine = 24;
// compilenode returning block80
  gc_frame_newslot(block80);
  Object block90 = alloc_Block(NULL, NULL, "lig/alioth/binary-trees", 26);
  gc_frame_newslot(block90);
  block_savedest(block90);
  Object closure91 = createclosure(4, "_apply");
setclosureframe(closure91, stackframe);
  addtoclosure(closure91, var_max_depth);
  addtoclosure(closure91, var_depth);
  addtoclosure(closure91, var_min_depth);
  addtoclosure(closure91, selfslot);
  struct UserObject *uo91 = (struct UserObject*)block90;
  uo91->data[0] = (Object)closure91;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees__apply91 = addmethod2pos(block90, "_apply", &meth_lig_47_alioth_47_binary_45_trees__apply91, 0);
int argcv_meth_lig_47_alioth_47_binary_45_trees__apply91[] = {0};
meth_meth_lig_47_alioth_47_binary_45_trees__apply91->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees__apply91);
  meth_meth_lig_47_alioth_47_binary_45_trees__apply91->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees__apply91->definitionLine = 24;
// compilenode returning block90
  gc_frame_newslot(block90);
  params[0] = block80;
  params[1] = block90;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call164 = callmethodflags(prelude, "while()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe79);
// compilenode returning call164
// Begin line 38
  setline(38);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit169 == NULL) {
    strlit169 = alloc_String("long lived tree of depth ");
    gc_root(strlit169);
  }
// compilenode returning strlit169
  int op_slot_left_168 = gc_frame_newslot(strlit169);
// compilenode returning *var_max_depth
  int op_slot_right_168 = gc_frame_newslot(*var_max_depth);
  params[0] = *var_max_depth;
  partcv[0] = 1;
  Object opresult171 = callmethod(strlit169, "++", 1, partcv, params);
// compilenode returning opresult171
  int op_slot_left_167 = gc_frame_newslot(opresult171);
  if (strlit172 == NULL) {
    strlit172 = alloc_String("""\x09"" check: ");
    gc_root(strlit172);
  }
// compilenode returning strlit172
  int op_slot_right_167 = gc_frame_newslot(strlit172);
  params[0] = strlit172;
  partcv[0] = 1;
  Object opresult174 = callmethod(opresult171, "++", 1, partcv, params);
// compilenode returning opresult174
  int op_slot_left_166 = gc_frame_newslot(opresult174);
  int callframe175 = gc_frame_new();
// compilenode returning *var_long_lived_tree
  gc_frame_newslot(*var_long_lived_tree);
  params[0] = *var_long_lived_tree;
  partcv[0] = 1;
  Object call176 = callmethodflags(self, "item_check", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe175);
// compilenode returning call176
  int op_slot_right_166 = gc_frame_newslot(call176);
  params[0] = call176;
  partcv[0] = 1;
  Object opresult178 = callmethod(opresult174, "++", 1, partcv, params);
// compilenode returning opresult178
  int op_slot_left_165 = gc_frame_newslot(opresult178);
  if (strlit179 == NULL) {
    strlit179 = alloc_String("");
    gc_root(strlit179);
  }
// compilenode returning strlit179
  int op_slot_right_165 = gc_frame_newslot(strlit179);
  params[0] = strlit179;
  partcv[0] = 1;
  Object opresult181 = callmethod(opresult178, "++", 1, partcv, params);
// compilenode returning opresult181
  params[0] = opresult181;
  Object call182 = gracelib_print(NULL, 1,  params);
// compilenode returning call182
// Begin line 40
  setline(40);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe184 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call185 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe184);
// compilenode returning call185
// compilenode returning call185
  int op_slot_left_183 = gc_frame_newslot(call185);
// compilenode returning *var_time
  int op_slot_right_183 = gc_frame_newslot(*var_time);
  params[0] = *var_time;
  partcv[0] = 1;
  Object diff187 = callmethod(call185, "-", 1, partcv, params);
// compilenode returning diff187
  *var_time = diff187;
  if (diff187 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 40
  setline(40);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_time
  int op_slot_left_190 = gc_frame_newslot(*var_time);
  Object num191 = alloc_Float64(2);
// compilenode returning num191
  int op_slot_right_190 = gc_frame_newslot(num191);
  params[0] = num191;
  partcv[0] = 1;
  Object opresult193 = callmethod(*var_time, ">=", 1, partcv, params);
// compilenode returning opresult193
  Object if189 = none;
  if (istrue(opresult193)) {
  if (strlit196 == NULL) {
    strlit196 = alloc_String(" * (execution time = ");
    gc_root(strlit196);
  }
// compilenode returning strlit196
  int op_slot_left_195 = gc_frame_newslot(strlit196);
// compilenode returning *var_time
  int op_slot_right_195 = gc_frame_newslot(*var_time);
  params[0] = *var_time;
  partcv[0] = 1;
  Object opresult198 = callmethod(strlit196, "++", 1, partcv, params);
// compilenode returning opresult198
  int op_slot_left_194 = gc_frame_newslot(opresult198);
  if (strlit199 == NULL) {
    strlit199 = alloc_String("s)");
    gc_root(strlit199);
  }
// compilenode returning strlit199
  int op_slot_right_194 = gc_frame_newslot(strlit199);
  params[0] = strlit199;
  partcv[0] = 1;
  Object opresult201 = callmethod(opresult198, "++", 1, partcv, params);
// compilenode returning opresult201
  params[0] = opresult201;
  Object call202 = gracelib_print(NULL, 1,  params);
// compilenode returning call202
    gc_frame_newslot(call202);
    if189 = call202;
  } else {
// Begin line 41
  setline(41);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit205 == NULL) {
    strlit205 = alloc_String(" * (execution time = ");
    gc_root(strlit205);
  }
// compilenode returning strlit205
  int op_slot_left_204 = gc_frame_newslot(strlit205);
// compilenode returning *var_time
  int op_slot_left_206 = gc_frame_newslot(*var_time);
  Object num207 = alloc_Float64(1000);
// compilenode returning num207
  int op_slot_right_206 = gc_frame_newslot(num207);
  params[0] = num207;
  partcv[0] = 1;
  Object prod209 = callmethod(*var_time, "*", 1, partcv, params);
// compilenode returning prod209
  int op_slot_right_204 = gc_frame_newslot(prod209);
  params[0] = prod209;
  partcv[0] = 1;
  Object opresult211 = callmethod(strlit205, "++", 1, partcv, params);
// compilenode returning opresult211
  int op_slot_left_203 = gc_frame_newslot(opresult211);
  if (strlit212 == NULL) {
    strlit212 = alloc_String("ms)");
    gc_root(strlit212);
  }
// compilenode returning strlit212
  int op_slot_right_203 = gc_frame_newslot(strlit212);
  params[0] = strlit212;
  partcv[0] = 1;
  Object opresult214 = callmethod(opresult211, "++", 1, partcv, params);
// compilenode returning opresult214
  params[0] = opresult214;
  Object call215 = gracelib_print(NULL, 1,  params);
// compilenode returning call215
    gc_frame_newslot(call215);
    if189 = call215;
  }
// compilenode returning if189
  gc_frame_end(frame);
  return if189;
}
Object meth_lig_47_alioth_47_binary_45_trees_nil218(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 4, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "nil");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_nil = getfromclosure(closure, 0);
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
// compilenode returning *var_nil
  gc_frame_end(frame);
  return *var_nil;
}
Object module_lig_47_alioth_47_binary_45_trees_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(6, 6);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/alioth/binary-trees>");
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
  struct StackFrameObject *stackframe = alloc_StackFrame(6, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[1];
  int partcv[1];
Object *var_sys = alloc_var();
  Object *var_nil = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "nil");
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure0 = createclosure(1, "item_check");
setclosureframe(closure0, stackframe);
  addtoclosure(closure0, var_nil);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = (Object)closure0;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees_item_check0 = addmethod2pos(self, "item_check", &meth_lig_47_alioth_47_binary_45_trees_item_check0, 1);
int argcv_meth_lig_47_alioth_47_binary_45_trees_item_check0[] = {1};
meth_meth_lig_47_alioth_47_binary_45_trees_item_check0->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees_item_check0);
  meth_meth_lig_47_alioth_47_binary_45_trees_item_check0->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees_item_check0->definitionLine = 3;
// compilenode returning 
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure21 = createclosure(1, "bottom_up_tree");
setclosureframe(closure21, stackframe);
  addtoclosure(closure21, var_nil);
  struct UserObject *uo21 = (struct UserObject*)self;
  uo21->data[2] = (Object)closure21;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21 = addmethod2pos(self, "bottom_up_tree", &meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21, 2);
int argcv_meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21[] = {2};
meth_meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21);
  meth_meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees_bottom_up_tree21->definitionLine = 10;
// compilenode returning 
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure45 = createclosure(2, "main");
setclosureframe(closure45, stackframe);
  addtoclosure(closure45, var_nil);
  addtoclosure(closure45, var_sys);
  struct UserObject *uo45 = (struct UserObject*)self;
  uo45->data[3] = (Object)closure45;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees_main45 = addmethod2pos(self, "main", &meth_lig_47_alioth_47_binary_45_trees_main45, 3);
int argcv_meth_lig_47_alioth_47_binary_45_trees_main45[] = {0};
meth_meth_lig_47_alioth_47_binary_45_trees_main45->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees_main45);
  meth_meth_lig_47_alioth_47_binary_45_trees_main45->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees_main45->definitionLine = 16;
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
  Object obj216 = alloc_userobj2(0,1, objclass216);
  gc_frame_newslot(obj216);
// OBJECT OUTER DEC outer
  adddatum2(obj216, self, 0);
  addmethodreal(obj216,"outer", &reader_lig_47_alioth_47_binary_45_trees_outer_217);
  Object oldself216 = self;
  struct StackFrameObject *oldstackframe216 = stackframe;
  stackframe = alloc_StackFrame(1, oldstackframe216);
  gc_frame_newslot((Object)stackframe);
  self = obj216;
  Object *oldselfslot216 = selfslot;
  selfslot = &stackframe->slots[0];
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
objclass216 = obj216->class;
  objclass216->definitionModule = modulename;
  objclass216->definitionLine = 2;
  self = oldself216;
  selfslot = oldselfslot216;
  stackframe = oldstackframe216;
// compilenode returning obj216
  *var_nil = obj216;
  if (obj216 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 39
  setline(39);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure218 = createclosure(1, "nil");
setclosureframe(closure218, stackframe);
  addtoclosure(closure218, var_nil);
  struct UserObject *uo218 = (struct UserObject*)self;
  uo218->data[4] = (Object)closure218;
  Method *meth_meth_lig_47_alioth_47_binary_45_trees_nil218 = addmethod2pos(self, "nil", &meth_lig_47_alioth_47_binary_45_trees_nil218, 4);
int argcv_meth_lig_47_alioth_47_binary_45_trees_nil218[] = {0};
meth_meth_lig_47_alioth_47_binary_45_trees_nil218->type = alloc_MethodType(1, argcv_meth_lig_47_alioth_47_binary_45_trees_nil218);
  meth_meth_lig_47_alioth_47_binary_45_trees_nil218->definitionModule = modulename;
  meth_meth_lig_47_alioth_47_binary_45_trees_nil218->definitionLine = 39;
// compilenode returning 
// compilenode returning none
// Begin line 43
  setline(43);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe219 = gc_frame_new();
  partcv[0] = 0;
  Object call220 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe219);
// compilenode returning call220
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
  module_lig_47_alioth_47_binary_45_trees_init();
  gracelib_stats();
  return 0;
}
