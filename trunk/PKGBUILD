# Maintainer: Jiachen Yang <farseerfc@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: ponsfoot <cabezon dot hashimoto at gmail dot com>
# Contributor: UTUMI Hirosi <utuhiro78 at yahoo dot co dot jp>

## Mozc compile option
_bldtype=Release
_mozc_commit=1882e33

## follow the submodule commits in https://github.com/fcitx/mozc/tree/fcitx/src/third_party
_abseil_cpp_commit=0f3bb46
_breakpad_commit=216cea7
_gtest_commit=703bd9c
_gyp_commit=caa6002
_japanese_usage_dictionary_commit=e5b3425
_jsoncpp_commit=11086dd
_protobuf_commit=fde7cf7

## the latest release from https://osdn.net/projects/ponsfoot-aur/storage/mozc/
_zipcode_rel=202011

_pkgbase=mozc
pkgname=fcitx-mozc
pkgdesc="Fcitx Module of A Japanese Input Method for Chromium OS, Windows, Mac and Linux (the Open Source Edition of Google Japanese Input)"
pkgver=2.26.4220.102.g1882e33
pkgrel=1
arch=('x86_64')
url="https://github.com/google/mozc"
license=('custom')
depends=('qt5-base' 'fcitx')
makedepends=('pkg-config' 'python' 'curl' 'gtk2' 'mesa' 'subversion' 'ninja' 'git' 'clang' 'python-six')
replaces=('mozc-fcitx')
conflicts=('mozc' 'mozc-server' 'mozc-utils-gui' 'mozc-fcitx' 'fcitx5-mozc')
source=(git+https://github.com/fcitx/mozc.git#commit=${_mozc_commit}
        https://osdn.net/projects/ponsfoot-aur/storage/mozc/jigyosyo-${_zipcode_rel}.zip
        https://osdn.net/projects/ponsfoot-aur/storage/mozc/x-ken-all-${_zipcode_rel}.zip
        git+https://chromium.googlesource.com/breakpad/breakpad#commit=${_breakpad_commit}
        git+https://github.com/google/googletest.git#commit=${_gtest_commit}
        git+https://chromium.googlesource.com/external/gyp#commit=${_gyp_commit}
        git+https://github.com/hiroyuki-komatsu/japanese-usage-dictionary.git#commit=${_japanese_usage_dictionary_commit}
        git+https://github.com/open-source-parsers/jsoncpp.git#commit=${_jsoncpp_commit}
        git+https://github.com/google/protobuf.git#commit=${_protobuf_commit}
        git+https://github.com/abseil/abseil-cpp.git#commit=${_abseil_cpp_commit}
        0001-fix-install_fcitx-translation-files.patch
	)
sha512sums=('SKIP'
            '0ef2d0abd9744900f9a50f941cf1f9b47640f3643c14a1be1761bcf0bd1053cb93560203c25280f58fccbd8ec98b9ca2e21c5d5a59844bbbffc9c988dfcf7bed'
            '8a35672b4a525d8e4f3303bd83c6bf6075cd4f10e703bf656a4c9328f18a8783c3049b749092e6e8be57eaddce4f889e9dacae9b3b72ba7bb9240a0f5a93fd34'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'SKIP'
            'd6e055f69c628aa447ab7f59f9ab903f701e4ba0a1683d7f96a677504b26160a0fb97430ed9b37755473fdc20087eb83104710cbb2d8c3a4991c18128c7eef42')
validpgpkeys=('2CC8A0609AD2A479C65B6D5C8E8B898CBF2412F9')  # Weng Xuetian

pkgver(){
  cd mozc
  # change pkgver is OK because we fixed commit
  # parse major.minor.buildid from version template, revision is fixed to 102 for Linux
  _bzr_ver=$(sed 's/ //g;$ a echo $MAJOR.$MINOR.$BUILD.102' src/data/version/mozc_version_template.bzl | source /dev/stdin)
  printf "%s.g%s" "${_bzr_ver}" "${_mozc_commit}"
}

prepare() {
  cd "$srcdir/mozc"
  git submodule init
  git config submodule.src/third_party/breakpad.url "$srcdir/breakpad"
  git config submodule.src/third_party/gtest.url "$srcdir/googletest"
  git config submodule.src/third_party/gyp.url "$srcdir/gyp"
  git config submodule.src/third_party/japanese_usage_dictionary.url "$srcdir/japanese-usage-dictionary"
  git config submodule.src/third_party/jsoncpp.url "$srcdir/jsoncpp"
  git config submodule.src/third_party/protobuf.url "$srcdir/protobuf"
  git config submodule.src/third_party/abseil-cpp.url "$srcdir/abseil-cpp"
  git submodule update

  patch -Np1 -i "$srcdir/0001-fix-install_fcitx-translation-files.patch"

  cd src
  # Generate zip code seed
  echo "Generating zip code seed..."
  PYTHONPATH="$PWD:$PYTHONPATH" python dictionary/gen_zip_code_seed.py --zip_code="${srcdir}/x-ken-all.csv" --jigyosyo="${srcdir}/JIGYOSYO.CSV" >> data/dictionary_oss/dictionary09.txt
  echo "Done."

  # disable fcitx5 target
  rm unix/fcitx5/fcitx5.gyp
  
  ## use libstdc++ instead of libc++
  sed "/stdlib=libc++/d;/-lc++/d" -i gyp/common.gypi
}

build() {
  # Fix compatibility with google-glog 0.3.3 (symbol conflict)
  CFLAGS="${CFLAGS} -fvisibility=hidden"
  CXXFLAGS="${CXXFLAGS} -fvisibility=hidden"
  export _bldtype

  cd mozc/src

  _targets="server/server.gyp:mozc_server gui/gui.gyp:mozc_tool unix/fcitx/fcitx.gyp:fcitx-mozc"

  QTDIR=/usr GYP_DEFINES="document_dir=/usr/share/licenses/$pkgname use_libzinnia=1" python build_mozc.py gyp
  python build_mozc.py build -c $_bldtype $_targets
  #../scripts/build

  # Extract license part of mozc
  head -n 29 server/mozc_server.cc > LICENSE
}

package() {
  cd mozc/src
  export PREFIX="${pkgdir}/usr"
  export _bldtype
  ../scripts/install_server

  install -d "${pkgdir}/usr/share/licenses/$pkgname/"
  install -m 644 LICENSE data/installer/*.html "${pkgdir}/usr/share/licenses/${pkgname}/"

  install -d "${PREFIX}/share/fcitx/addon"
  install -d "${PREFIX}/share/fcitx/inputmethod"
  install -d "${PREFIX}/lib/fcitx"
  ../scripts/install_fcitx
}
