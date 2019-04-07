[@bs.module "bizcharts"] external reactClass: ReasonReact.reactClass = "Axis";

[@bs.deriving jsConverter]
type position = [ | `top | `right | `bottom | `left];

module TitleProp = {
  type t;

  external bool: bool => t = "%identity";
  external obj: Js.t('a) => t = "%identity";
  external null: Js.Nullable.t('b) => t = "%identity";
};

[@bs.obj]
external makeProps:
  (
    ~name: string,
    ~visible: bool=?,
    ~position: string=?,
    ~title: TitleProp.t=?,
    ~line: Js.t('a)=?,
    ~tickLine: Js.t('b)=?,
    ~label: Js.t('c)=?,
    ~grid: Js.t('d)=?,
    ~subTickCount: int=?,
    ~subTickLine: Js.t('e)=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~name,
      ~visible=?,
      ~position=?,
      ~title=?,
      ~line=?,
      ~tickLine=?,
      ~label=?,
      ~grid=?,
      ~subTickCount=?,
      ~subTickLine=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~name,
        ~visible?,
        ~position=?Belt.Option.map(position, positionToJs),
        ~title?,
        ~line?,
        ~tickLine?,
        ~label?,
        ~grid?,
        ~subTickCount?,
        ~subTickLine?,
        (),
      ),
    children,
  );
