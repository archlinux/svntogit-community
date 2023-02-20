# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: Dominik Heidler <dheidler@gmail.com>
# Contributor:	Jonatan Sastre <jsastreh [ at ] hotmail.com>

# NOTE: sonames change on each release, so *all* dependent packages have to be rebuilt!
pkgbase=gnuradio
pkgname=(gnuradio gnuradio-companion)
pkgver=3.10.5.0
pkgrel=4
pkgdesc="General purpose DSP and SDR toolkit with drivers for usrp and fcd."
arch=(x86_64)
url="https://gnuradio.org"
license=(GPL3)
depends=(
  codec2  # host
  gcc-libs
  glibc
  gmp  # host
  gsl  # host
  libad9361  # gnuradio.iio
  libuhd  # gnuradio.uhd
  libunwind
  libvolk  # host
  pybind11  # host
  python-click  # host
  python-click-plugins  # host
  python-mako  # host
  python-matplotlib
  python-numpy  # host
  python-packaging  # host
  # python-pygccxml  # gnuradio.modtool  # TODO: package
  python-pyyaml  # various
  python-pyzmq  # gnuradio.zeromq
  python-scipy
  python-thrift  # runtime
  sdl12-compat  # gnuradio.video_sdl
  soapysdr  # gnuradio.soapy
  spdlog  # host
  thrift  # host
)
makedepends=(
  alsa-lib  # gnuradio.audio
  boost
  # cppzmq  # gnuradio.zeromq  # TODO: package
  cmake
  fftw  # host
  fmt
  gtk3
  jack  # gnuradio.audio
  libiio  # gnuradio.iio
  libsndfile  # host
  portaudio  # gnuradio.audio
  python-cairo  # gnuradio.companion
  python-gobject  # gnuradio.companion
  python-lxml  # gnuradio.companion
  python-pyqt5  # gnuradio.qtgui
  python-pyqtgraph  # gnuradio.qtgui
  python-pytest  # only required for tests
  qt5-base
  qwt  # gnuradio.qtgui
  zeromq  # gnuradio.zeromq
)
checkdepends=(
  python-jsonschema
  python-setuptools  # gnuradio.modtool
  xorg-server-xvfb
)
source=(
  $pkgbase-$pkgver.tar.gz::https://github.com/$pkgbase/$pkgbase/archive/v$pkgver/$pkgbase-v$pkgver.tar.gz
  https://github.com/gnuradio/gnuradio/releases/download/v$pkgver/$pkgbase-$pkgver.tar.gz.asc
  21-fcd.rules
)
validpgpkeys=(
  'B90DDFAC56989BF62262EB812987C77CBB8ED9B2'  # GNU Radio Project (Admin) <admin@gnuradio.org>
  'D74F9F146E7F755783583158B343B2BA293E5174'  # Marcus Müller (GNU Radio Maintainer) <mmueller@gnuradio.org>
  '723EC3A2B90533C6B93DFBC8ED797743F7951435'  # GNU Radio (Software Signing Key) <info@gnuradio.org>
)
sha512sums=('82f3028cbcb0175f9f354b19613ee59b052881b894c6d668d04235acda2e3be0ca2713642141a917264e70039f23795c647c47364af9ffad63f108da517d77c5'
            'SKIP'
            '6f02dc8e20a7a1cd11099c851a7c8427fcd21e9652e6cddd0a72ca747b0e93cd4fd1b7b7b7e426b6231348bcc34fb2417716a2f03c92ec141889edc65031c3a0')
b2sums=('c21e310d4cc50112e7d2085be5a82f4eb633305936004cc60cabbac340a0cbd0016bb5f24229380c36281c4e52e6763c5152ceb6ad0f2efc43bd28b2b55c4df8'
        'SKIP'
        '83657a141a7a4fc52ae62e19b480fd7b7e651efffc2186d3eb96e8612beffbbe71b434a2323ae37c74465ff6a959a4ca1f9c9db5ed02ab641f1784e704ab5f4d')

build() {
  local cmake_options=(
    -D CMAKE_INSTALL_PREFIX=/usr
    -D CMAKE_BUILD_TYPE=None
    -D ENABLE_GR_ANALOG=ON
    -D ENABLE_GR_AUDIO=ON
    -D ENABLE_GR_BLOCKS=ON
    -D ENABLE_GR_BLOCKTOOL=ON
    -D ENABLE_GR_CHANNELS=ON
    -D ENABLE_GR_CTRLPORT=ON
    -D ENABLE_GR_DIGITAL=ON
    -D ENABLE_GR_DTV=ON
    -D ENABLE_GR_FEC=ON
    -D ENABLE_GR_FFT=ON
    -D ENABLE_GR_FILTER=ON
    -D ENABLE_GR_IIO=ON
    -D ENABLE_GR_MODTOOL=ON
    -D ENABLE_GR_NETWORK=ON
    -D ENABLE_GR_PDU=ON
    -D ENABLE_GR_QTGUI=ON
    -D ENABLE_GR_SOAPY=ON
    -D ENABLE_GR_TRELLIS=ON
    -D ENABLE_GR_UHD=ON
    -D ENABLE_GR_UTILS=ON
    -D ENABLE_GR_VIDEO_SDL=ON
    -D ENABLE_GR_VOCODER=ON
    -D ENABLE_GR_WAVELET=ON
    -D ENABLE_GR_ZEROMQ=ON
    -D ENABLE_GRC=ON
    -D ENABLE_POSTINSTALL=OFF  # we distribute freedesktop integration directly
    -W no-dev
    -B build
    -S $pkgbase-$pkgver
  )

  cmake "${cmake_options[@]}"
  cmake --build build --verbose
}

check() {
  # NOTE: disable broken tests
  xvfb-run ctest --test-dir build --output-on-failure -E 'pfb_synthesizer|filter_qa_fir_filter_with_buffer.cc'
}

package_gnuradio() {
  depends+=(
    alsa-lib libasound.so
    boost-libs libboost_{program_options,thread}.so
    fftw libfftw3f.so libfftw3f_threads.so
    fmt libfmt.so
    jack libjack.so
    libiio libiio.so
    libsndfile libsndfile.so
    portaudio libportaudio.so
    spdlog libspdlog.so
    zeromq libzmq.so
  )
  optdepends=(
    'gnuradio-companion: for GUI frontend'
    'python-setuptools: for gr_modtool'
  )
  provides=(
    libgnuradio-analog.so
    libgnuradio-audio.so
    libgnuradio-blocks.so
    libgnuradio-channels.so
    libgnuradio-digital.so
    libgnuradio-dtv.so
    libgnuradio-fec.so
    libgnuradio-fft.so
    libgnuradio-filter.so
    libgnuradio-iio.so
    libgnuradio-network.so
    libgnuradio-pmt.so
    libgnuradio-qtgui.so
    libgnuradio-runtime.so
    libgnuradio-soapy.so
    libgnuradio-trellis.so
    libgnuradio-uhd.so
    libgnuradio-video-sdl.so
    libgnuradio-vocoder.so
    libgnuradio-wavelet.so
    libgnuradio-zeromq.so
  )
  backup=(
    etc/$pkgbase/conf.d/00-grc-docs.conf
    etc/$pkgbase/conf.d/gnuradio-runtime.conf
    etc/$pkgbase/conf.d/gr-audio{,-{alsa,jack,oss,portaudio}}.conf
    etc/$pkgbase/conf.d/gr-qtgui.conf
    etc/$pkgbase/conf.d/gr_log_default.conf
    etc/$pkgbase/conf.d/grc.conf
    etc/$pkgbase/conf.d/modtool.conf
  )

  DESTDIR="$pkgdir" cmake --install build
  install -vDm 644 21-fcd.rules -t "$pkgdir/usr/lib/udev/rules.d/"
  # remove optimized bytecode files: https://github.com/gnuradio/gnuradio/issues/6463
  find "$pkgdir" -type f -iname "*.pyo" -delete
  # remove unneeded freedesktop integration tooling: https://github.com/gnuradio/gnuradio/issues/6464
  rm -frv "$pkgdir/usr/libexec/"
}

package_gnuradio-companion() {
  pkgdesc="GUI frontend for gnuradio and SDR."
  depends=(
    gnuradio
    python-cairo
    python-gobject
    python-lxml
    python-opengl
    python-pyqt5
    python-pyqtgraph
    qt5-base
    qwt
  )
  # NOTE: we are only pulling in dependencies here
}
