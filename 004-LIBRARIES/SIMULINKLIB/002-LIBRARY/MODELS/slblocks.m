function blkStruct = slblocks
  % This function specifies that the library should appear
  % in the Library Browser
  % and be cached in the browser repository
  
  blkStruct.MaskDisplay = '';
  Browser(1).Library = 'SIMULINKLIB';
  Browser(1).Name    = 'Mike Alger''s Simulink Library';
  Browser(1).IsFlat  = 0;
  blkStruct.Browser = Browser;