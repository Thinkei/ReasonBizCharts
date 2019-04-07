[@bs.module "bizcharts"]
external reactClass: ReasonReact.reactClass = "Tooltip";

[@bs.deriving jsConverter]
type position = [ | `top | `right | `bottom | `left];

[@bs.deriving jsConverter]
type trigger = [ | `mousemouse | `click | `none];

[@bs.obj]
external makeProps: (~triggerOn: string=?, ~position: string=?, unit) => _ =
  "";

let make = (~triggerOn=?, ~position=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~triggerOn=?Belt.Option.map(triggerOn, triggerToJs),
        ~position=?Belt.Option.map(position, positionToJs),
        (),
      ),
    children,
  );
