module AudioContextRe: {

  /* Abstract type to represent AudioContext of WebAudioApi */
  type t;

  /* Variant type to represent the state of an AudioContext */
  type state = Suspended | Running | Closed;

  /* Exception raised if a string is not a valid state representation */
  exception WrongState string;

  /* Create a new AudioContext */
  let create_context : unit => t;

  /* Close a context */
  let close_context : t => unit;

  /*
  Represents an ever-increasing hardware time in seconds used for scheduling.
  It starts at 0.
  */
  let current_time : t => float;

  /*
  Represents the sample rate (in samples per second) used by all nodes in this context.
  The sample-rate of an AudioContext cannot be changed.
  */
  let sample_rate : t => float;

  /* Returns the current state of the AudioContext */
  let state : t => state;

  /*
  Asynchronously decodes audio file data contained in an ArrayBuffer.
  In this case, the ArrayBuffer is usually loaded from an XMLHttpRequest's response attribute after setting the responseType to arraybuffer.
  This method only works on complete files, not fragments of audio files. */
  let decode_audio_data : t => Js_typed_array.array_buffer;

};

