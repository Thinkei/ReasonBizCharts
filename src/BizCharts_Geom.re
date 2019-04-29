[@bs.deriving jsConverter]
type geoType = [
  | `point
  | `path
  | `line
  | `area
  | `interval
  | `polygon
  | `schema
  | `edge
  | `heatmap
  | `pointStack
  | `pointJitter
  | `pointDodge
  | `intervalStack
  | `intevalDodge
  | `intervalSymmetric
  | `areaStack
  | `lineStack
  | `schemaDodge
];

module ColorProp = {
  type t;

  module Arg = {
    type t;

    external string: string => t = "%identity";
    external array: array(string) => t = "%identity";
    external func: ('a => 'b) => t = "%identity";
  };

  external string: string => t = "%identity";
  external array: array(Arg.t) => t = "%identity";
};

module External = {
  [@bs.module "bizcharts"] [@react.component]
  external make:
    (
      ~_type: string=?,
      ~adjust: Js.t('a)=?,
      ~position: string=?,
      ~color: ColorProp.t=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Geom";
};

[@react.component]
let make = (~_type, ~adjust=?, ~position=?, ~color=?, ~children=?) =>
  <External
    _type={geoTypeToJs(_type)}
    ?adjust
    ?color
    ?position
    ?children
  />;
