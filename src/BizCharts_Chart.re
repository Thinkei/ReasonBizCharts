[@bs.module "bizcharts"] external reactClass: ReasonReact.reactClass = "Chart";

[@bs.deriving jsConverter]
type renderer = [ | `svg | `canvas];
type scale;
type padding;
type background;
type filter;

[@bs.obj]
external makeProps:
  (
    ~renderer: string=?,
    ~forceFit: bool=?,
    ~width: int=?,
    ~height: int=?,
    ~data: array(Js.t('a))=?,
    ~scale: Js.t('b)=?,
    ~placeholder: string=?,
    /* ~padding: padding=?, */
    ~animate: bool=?,
    /* ~background: background=?, */
    /* ~plotBackground: background=?, */
    ~pixelRatio: int=?,
    /* ~filter: filter=?, */
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~theme: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~renderer=?,
      ~forceFit=?,
      ~width=?,
      ~height=?,
      ~data=?,
      ~scale=?,
      ~placeholder=?,
      ~padding=?,
      ~animate=?,
      ~background=?,
      ~plotBackground=?,
      ~pixelRatio=?,
      ~filter=?,
      ~className=?,
      ~style=?,
      ~theme=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~renderer=?Belt.Option.map(renderer, rendererToJs),
        ~forceFit?,
        ~width?,
        ~height?,
        ~data?,
        ~scale?,
        ~placeholder?,
        /* ~padding?, */
        ~animate?,
        /* ~background?, */
        /* ~plotBackground?, */
        ~pixelRatio?,
        /* ~filter?, */
        ~className?,
        ~style?,
        ~theme?,
        (),
      ),
    children,
  );
