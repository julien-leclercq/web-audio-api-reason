open WebAudioApiTypes;

module type AudioNodeType = {
  type t;
};

/* module signature for AudioNode childs */
module MakeAudioNode = fun (N: AudioNodeType) => {
  include N;

  external get_context : t => audio_context = "" [@@bs.get];
  external get_number_of_inputs : t => int = "numberOfInputs" [@@bs.get];
  external get_number_of_outputs : t => int = "numberOfOutputs" [@@bs.get];
  external get_channel_count : t => int = "channelCount" [@@bs.get];
  external _set_channel_count : t => int => unit = "channel_count" [@@bs.set];

  let set_channel_count node channel_number => {
    _set_channel_count node channel_number;
    node;
  };
};


