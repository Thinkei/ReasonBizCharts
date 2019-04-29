[@bs.module "bizcharts"]
external reactClass: ReasonReact.reactClass = "Tooltip";

[@bs.deriving jsConverter]
type position = [ | `top | `right | `bottom | `left];

[@bs.deriving jsConverter]
type trigger = [ | `mousemouse | `click | `none];

[@bs.module "bizcharts"] [@react.component]
external make:
  (~triggerOn: trigger=?, ~position: position=?, ~children: React.element=?) =>
  React.element =
  "Tooltip";
