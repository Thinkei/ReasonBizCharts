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

[@bs.module "bizcharts"] [@react.component]
external make:
  (
    ~content: ContentProp.t=?,
    ~labelLine: Js.t('a)=?,
    ~offset: int=?,
    ~textStyle: Js.t('b)=?,
    ~autoRotate: bool=?,
    ~formatter: 'c => 'd=?,
    ~htmlTemplate: 'e => 'f=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Label";
