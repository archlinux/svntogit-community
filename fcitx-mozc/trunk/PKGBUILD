# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: ponsfoot <cabezon dot hashimoto at gmail dot com>
# Contributor: UTUMI Hirosi <utuhiro78 at yahoo dot co dot jp>

## Mozc compile option
_bldtype=Release

_mozc_rev=afb03ddfe72dde4cf2409863a3bfea160f7a66d8
_japanese_usage_dictionary_rev=a4a66772e33746b91e99caceecced9a28507e925
_gyp_rev=4ec6c4e3a94bd04a6da2858163d40b2429b8aad1 
_protobuf_rev=92a7e778e7394386f413cec28d67a07630f784b1
_zipcode_rel=201810

_pkgbase=mozc
pkgname=fcitx-mozc
pkgdesc="Fcitx Module of A Japanese Input Method for Chromium OS, Windows, Mac and Linux (the Open Source Edition of Google Japanese Input)"
pkgver=2.23.2815.102
_fcitx_patchver=${pkgver}.1
pkgrel=4
arch=('x86_64')
url="https://github.com/google/mozc"
license=('custom')
depends=('qt5-base' 'fcitx' 'zinnia')
makedepends=('pkg-config' 'python2' 'curl' 'gtk2' 'mesa' 'subversion' 'ninja' 'git' 'clang')
replaces=('mozc-fcitx')
conflicts=('mozc' 'mozc-server' 'mozc-utils-gui' 'mozc-fcitx')
source=(
	git+https://github.com/google/mozc.git#commit=${_mozc_rev}
	pr444.patch::https://github.com/google/mozc/pull/444/commits/82d38f929882a9c62289b179c6fe41efed249987.patch
	japanese_usage_dictionary::git+https://github.com/hiroyuki-komatsu/japanese-usage-dictionary.git#commit=${_japanese_usage_dictionary_rev}
	mozc-gyp::git+https://chromium.googlesource.com/external/gyp#commit=${_gyp_rev}
	git+https://github.com/google/protobuf.git#commit=${_protobuf_rev}
	https://downloads.sourceforge.net/pnsft-aur/x-ken-all-${_zipcode_rel}.zip
	https://downloads.sourceforge.net/pnsft-aur/jigyosyo-${_zipcode_rel}.zip
	https://download.fcitx-im.org/fcitx-mozc/fcitx-mozc-${_fcitx_patchver}.patch{,.sig}
        https://download.fcitx-im.org/fcitx-mozc/fcitx-mozc-icon.tar.gz)
sha512sums=('SKIP'
            '0c6ebf6a8579b6fc3f7d6b292d1aca6b1a3825030e78b4f46bb1c49bcf1c559ae82081bd459de5ee3aa7bf803af83e8ddc77157553da342f030442934e4877fb'
            'SKIP'
            'SKIP'
            'SKIP'
            '59d0a5e62c698ebc64008f1fb2ed68ebbbd7798d9d95f2e4852261fb09d53e9f8c102f385ed8f2001e3da6c2a0a50d64f1f20e70671948b492f972c487655efe'
            'daf41f63bd1afc0937beb12aa007ead8a239fabc3af2237e4adf75238b0e0e520f6051f5a98d413a541f901e17a1488eb3fad6d0bba1f1561987365236d64146'
            'e0d4645df919838f0fe31a97bf6dd759c222a696f68133f7584d2c771f70734ea634a25bebb03a756221000d3552423207ee5163d75778dbf480b6e267ba4cd0'
            'SKIP'
            '5507c637e5a65c44ccf6e32118b6d16647ece865171b9a77dd3c78e6790fbd97e6b219e68d2e27750e22074eb536bccf8d553c295d939066b72994b86b2f251a')
validpgpkeys=('2CC8A0609AD2A479C65B6D5C8E8B898CBF2412F9')  # Weng Xuetian

prepare() {
  mv mozc-gyp gyp

  cd mozc
  # Apply gcc8.1 patch in PR#444
  patch -Np1 -i "$srcdir/pr444.patch"

  cd src

  # Apply fcitx patch
  rm unix/fcitx -rf
  patch -Np2 -i "$srcdir/fcitx-mozc-${_fcitx_patchver}.patch"
  # Disable fcitx5 specific building 
  rm unix/fcitx5 -rf

  # Adjust to use python2
  find . -name  \*.py        -type f -exec sed -i -e "1s|python.*$|python2|"  {} +
  find . -regex '.*\.gypi?$' -type f -exec sed -i -e "s|'python'|'python2'|g" {} +

  # Generate zip code seed
  msg "Generating zip code seed..."
  PYTHONPATH="$PWD:$PYTHONPATH" python2 dictionary/gen_zip_code_seed.py --zip_code="${srcdir}/x-ken-all.csv" --jigyosyo="${srcdir}/JIGYOSYO.CSV" >> data/dictionary_oss/dictionary09.txt
  msg "Done."

  # Copy third party deps
  cd "$srcdir"
  for dep in gyp protobuf japanese_usage_dictionary
  do
    cp -a $dep mozc/src/third_party/
  done
}

build() {
  # Fix compatibility with google-glog 0.3.3 (symbol conflict)
  CFLAGS="${CFLAGS} -fvisibility=hidden"
  CXXFLAGS="${CXXFLAGS} -fvisibility=hidden"

  cd mozc/src

  _targets="server/server.gyp:mozc_server gui/gui.gyp:mozc_tool unix/fcitx/fcitx.gyp:fcitx-mozc"

  QTDIR=/usr GYP_DEFINES="document_dir=/usr/share/licenses/$pkgname use_libzinnia=1" python2 build_mozc.py gyp
  python2 build_mozc.py build -c $_bldtype $_targets

  # Extract license part of mozc
  head -n 29 server/mozc_server.cc > LICENSE
}

package() {
  cd mozc/src
  install -D -m 755 out_linux/${_bldtype}/mozc_server "${pkgdir}/usr/lib/mozc/mozc_server"
  install    -m 755 out_linux/${_bldtype}/mozc_tool   "${pkgdir}/usr/lib/mozc/mozc_tool"

  install -d "${pkgdir}/usr/share/licenses/$pkgname/"
  install -m 644 LICENSE data/installer/*.html "${pkgdir}/usr/share/licenses/${pkgname}/"

  for mofile in out_linux/${_bldtype}/gen/unix/fcitx/po/*.mo
  do
    filename=`basename $mofile`
    lang=${filename/.mo/}
    install -D -m 644 "$mofile" "${pkgdir}/usr/share/locale/$lang/LC_MESSAGES/fcitx-mozc.mo"
  done

  install -D -m 755 out_linux/${_bldtype}/fcitx-mozc.so "${pkgdir}/usr/lib/fcitx/fcitx-mozc.so"
  install -D -m 644 unix/fcitx/fcitx-mozc.conf "${pkgdir}/usr/share/fcitx/addon/fcitx-mozc.conf"
  install -D -m 644 unix/fcitx/mozc.conf "${pkgdir}/usr/share/fcitx/inputmethod/mozc.conf"

  install -d "${pkgdir}/usr/share/fcitx/mozc/icon"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-alpha_full.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-alpha_full.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-alpha_half.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-alpha_half.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-direct.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-direct.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-hiragana.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-hiragana.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-katakana_full.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-katakana_full.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-katakana_half.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-katakana_half.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-dictionary.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-dictionary.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-properties.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-properties.png"
  install -m 644 "$srcdir/fcitx-mozc-icons/mozc-tool.png" "${pkgdir}/usr/share/fcitx/mozc/icon/mozc-tool.png"
}
