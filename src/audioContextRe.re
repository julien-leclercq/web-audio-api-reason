open WebAudioApiTypes;

module AudioContextRe = {

  type t = audio_context;
  type state = Suspended | Running | Closed;

  exception WrongState string;

  external _create_context : unit => t = "AudioContext" [@@bs.new];
  external _close_context : t  => unit = "close" [@@bs.send];
  external _current_time : t => float = "currentTime" [@@bs.get];
  external _sample_rate : t => float = "sampleRate" [@@bs.get];
  external _state : t => string = "state" [@@bs.get];
  external _decode_audio_data : t => array_buffer => promise array_buffer = "decodeAudioData" [@@bs.send];
  external _create_buffer_source : t => audio_buffer_source_node = "createBufferSource" [@@bs.send];

  let create_context () => _create_context ();

  let close_context context => _close_context context ;

  let current_time context => _current_time context ;

  let sample_rate context => _sample_rate context ;

  let state_of_string context_string => switch  (context_string) {
  | "suspended" => Suspended
  | "running" => Running
  | "closed" => Closed
  | _ => raise (WrongState (context_string ^ " is not a valid audio context state"))
  };

  let state context =>
    context
    |> _state
    |> state_of_string;

  let decode_audio_data context array => _decode_audio_data context array;

  let create_buffer_source context => _create_buffer_source context;

};
