[@bs.module "bizcharts"] external reactClass: ReasonReact.reactClass = "Label";

module ContentProp = {
  type t;

  module Arg = {
    type t;

    external string: string => t = "%identity";
    external func: ('a => 'b) => t = "%identity";
  };

  external string: string => t = "%identity";
  external array: array(Arg.t) => t = "%identity";
};

[@bs.obj]
external makeProps:
  (
    ~content: ContentProp.t=?,
    ~labelLine: Js.t('a)=?,
    ~offset: int=?,
    ~textStyle: Js.t('b)=?,
    ~autoRotate: bool=?,
    ~formatter: 'c => 'd=?,
    ~htmlTemplate: 'e => 'f=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~content=?,
      ~labelLine=?,
      ~offset=?,
      ~textStyle=?,
      ~autoRotate=?,
      ~formatter=?,
      ~htmlTemplate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~content?,
        ~labelLine?,
        ~offset?,
        ~textStyle?,
        ~autoRotate?,
        ~formatter?,
        ~htmlTemplate?,
        (),
      ),
    children,
  );
