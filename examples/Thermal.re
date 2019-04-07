open BizCharts;

let data = [|
  {"name": 0, "day": 0, "sales": 12},
  {"name": 0, "day": 1, "sales": 2},
  {"name": 0, "day": 2, "sales": 89},
  {"name": 0, "day": 3, "sales": 122},
  {"name": 0, "day": 4, "sales": 33},
  {"name": 1, "day": 0, "sales": 31},
  {"name": 1, "day": 1, "sales": 16},
  {"name": 1, "day": 2, "sales": 18},
  {"name": 1, "day": 3, "sales": 32},
  {"name": 1, "day": 4, "sales": 24},
  {"name": 2, "day": 0, "sales": 45},
  {"name": 2, "day": 1, "sales": 12},
  {"name": 2, "day": 2, "sales": 32},
  {"name": 2, "day": 3, "sales": 32},
  {"name": 2, "day": 4, "sales": 42},
  {"name": 3, "day": 0, "sales": 32},
  {"name": 3, "day": 1, "sales": 32},
  {"name": 3, "day": 2, "sales": 32},
  {"name": 3, "day": 3, "sales": 32},
  {"name": 3, "day": 4, "sales": 12},
  {"name": 4, "day": 0, "sales": 62},
  {"name": 4, "day": 1, "sales": 92},
  {"name": 4, "day": 2, "sales": 82},
  {"name": 4, "day": 3, "sales": 12},
  {"name": 4, "day": 4, "sales": 12},
  {"name": 5, "day": 0, "sales": 15},
  {"name": 5, "day": 1, "sales": 92},
  {"name": 5, "day": 2, "sales": 18},
  {"name": 5, "day": 3, "sales": 22},
  {"name": 5, "day": 4, "sales": 13},
|];

let scale = {
  "name": {
    "type": "cat",
    "values": [|"Tien", "Tung", "Nam", "Hieu", "Dang", "Long"|],
  },
  "day": {
    "type": "cat",
    "values": [|"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"|],
  },
};

let color =
  Geom.ColorProp.(
    array([|Arg.string("sales"), Arg.string("#BAE7FF-#1890FF-#0050B3")|])
  );

let component = ReasonReact.statelessComponent("ColorBlockDiagram");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <Chart renderer=`canvas data scale >
        <Axis name="name" />
        <Axis name="day" />
        <Tooltip />
        <Geom _type=`polygon position="name*day" color>
          <Label content={Label.ContentProp.string("sales")} />
        </Geom>
      </Chart>
    </div>,
};
