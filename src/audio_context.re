module type AudioContextReType = {
  type t;
  type state = Suspended | Running | Closed;
  exception WrongState string;
  let create_context : unit => t;
  let close_context : t => unit;
  let current_time : t => float;
  let sample_rate : t => float;
  let state : t => state;

};

module AudioContextRe: AudioContextReType = {

  /* Abstract type to represent AudioContext of WebAudioApi */
  type t;

  /* shortcut on Js_typed_array.array_buffer */
  type array_buffer = Js_typed_array.array_buffer;

  /* Variant type to represent the state of an AudioContext */
  type state = Suspended | Running | Closed;

  /* Exception raised if a string is not a valid state representation */
  exception WrongState string;

  external _create_context : unit => t = "AudioContext" [@@bs.new];
  external _close_context : t  => unit = "close" [@@bs.send];
  external _current_time : t => float = "currentTime" [@@bs.get];
  external _sample_rate : t => float = "sampleRate" [@@bs.get];
  external _state : t => string = "state" [@@bs.get];
  external _decode_audio_data : t => array_buffer = "decodeAudioData" [@@bs.send];

  /* Create a new AudioContext */
  let create_context () => _create_context ();

  /* Close a context */
  let close_context context => _close_context context ;

  /*
  Represents an ever-increasing hardware time in seconds used for scheduling.
  It starts at 0.
  */
  let current_time context => _current_time context ;

  /*
  Represents the sample rate (in samples per second) used by all nodes in this context.
  The sample-rate of an AudioContext cannot be changed.
  */
  let sample_rate context => _sample_rate context ;

  let state_of_string context_string => switch  (context_string) {
  | "suspended" => Suspended
  | "running" => Running
  | "closed" => Closed
  | _ => raise (WrongState (context_string ^ " is not a valid audio context state"))
  };

  /* Returns the current state of the AudioContext */
  let state context =>
    context
    |> _state
    |> state_of_string;
};
