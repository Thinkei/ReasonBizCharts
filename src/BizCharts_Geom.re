[@bs.module "bizcharts"] external reactClass: ReasonReact.reactClass = "Geom";

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

[@bs.obj]
external makeProps:
  (
    ~_type: string=?,
    ~adjust: Js.t('a)=?,
    ~position: string=?,
    ~color: ColorProp.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~_type=?, ~adjust=?, ~position=?, ~color=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_type=?Belt.Option.map(_type, geoTypeToJs),
        ~adjust?,
        ~position?,
        ~color?,
        (),
      ),
    children,
  );
