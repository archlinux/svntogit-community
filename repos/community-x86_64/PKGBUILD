# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: tobias <tobias@archlinux.org>
# Contributor: dibblethewrecker dibblethewrecker.at.jiwe.dot.org

pkgbase=rxvt-unicode
pkgname=('rxvt-unicode' 'rxvt-unicode-terminfo')
pkgver=9.31
pkgrel=2
arch=('x86_64')
url='http://software.schmorp.de/pkg/rxvt-unicode.html'
license=('GPL')
makedepends=(
  'libxft'
  'libxt'
  'libxext'
  'libxmu'
  'perl'
  'startup-notification'
  'libnsl'
  'libptytty'
  'signify'
)
source=("$pkgname-$pkgver.tar.bz2::http://dist.schmorp.de/rxvt-unicode/$pkgname-$pkgver.tar.bz2"
        "$pkgname-$pkgver.tar.bz2.signature::http://dist.schmorp.de/rxvt-unicode/$pkgname-$pkgver.tar.bz2.sig"
        "$pkgname-$pkgver.pub::http://dist.schmorp.de/signing-key.pub"
        'urxvt.desktop'
        'urxvtc.desktop'
        'urxvt-tabbed.desktop')
sha256sums=('aaa13fcbc149fe0f3f391f933279580f74a96fd312d6ed06b8ff03c2d46672e8'
            'fd43ac9f271437389c97d5ee208f414abd0aab01a0824c29533a4077ba7d6f3c'
            '48ef5720d77a870f25737b8f66fe2c1f88a01810013df70cb8155add904288e4'
            '5f9c435d559371216d1c5b49c6ec44bfdb786b12d925d543c286b0764dea0319'
            '91536bb27c6504d6cb0d33775a0c4709a4b439670b900f0c278c25037f19ad66'
            'ccd7c436e959bdc9ab4f15801a67c695b382565b31d8c352254362e67412afcb')
sha512sums=('4d14ecbbb62de1b1c717277f5aae5cfb536e11392f2d4b82c884c1713f437fce8e9dd69a328fa353a55d068d8ee4121a31900f45191acec172d5dc76652b6255'
            '7f3b836dd46c1a70384420b77181b11cbb598ac6e7ab144e0ce132c99e84caa4eb76c95f532fbeec02e0e549f22269c60b369ece677aed14c0aed7092ef1dbf9'
            'a09a434387e22612a9225ddfa444044977712c6410efe8a77a33d8aa607bd1acbef2a1da08b62e21a4b070f0974ba94ae907ac0452b5d060e33a1c051a7780e4'
            '7184714a908071a4e8e5c065c5f90255e94dfd072df459c8d6f66fca3647781b3d1f6908b9303bcfd0d5b3f2e3822a8d66efaaa8a7c4d44f6e682839031a6e99'
            'aa501eeeb220ba03b3f101b160230612efbca87694fef88c469b2976d29769c24b34576ea82f6c7941fad6039ac776f32e397add9b957b49bf2e84aeb67b66d6'
            '18c7afb0c3eb8c832893b9ead09d25374b70ae1cd5479a5291d11794906c53daa6f1a1bf698b37efda062bb2b991cacac53a0a6c185ca416b8718fde2bb6a7af')

prepare() {
  # hacking around to validate with signify
  mv -v "$pkgname-$pkgver.tar.bz2."{signature,sig}
  signify -V -p "$pkgname-$pkgver.pub" -m "$pkgname-$pkgver.tar.bz2"
}

build() {
  cd ${pkgname}-${pkgver}
  # we disable smart-resize (FS#34807)
  # do not specify --with-terminfo (FS#46424)
  # do not specify --disable-frills (FS#77474)
  ./configure \
    --prefix=/usr \
    --enable-256-color \
    --enable-combining \
    --enable-fading \
    --enable-font-styles \
    --enable-iso14755 \
    --enable-keepscrolling \
    --enable-lastlog \
    --enable-mousewheel \
    --enable-next-scroll \
    --enable-perl \
    --enable-pointer-blank \
    --enable-rxvt-scroll \
    --enable-selectionscrolling \
    --enable-slipwheeling \
    --disable-smart-resize \
    --enable-startup-notification \
    --enable-transparency \
    --enable-unicode3 \
    --enable-utmp \
    --enable-wtmp \
    --enable-xft \
    --enable-xim \
    --enable-xterm-scroll \
    --disable-pixbuf
  make
}

package_rxvt-unicode() {
  pkgdesc='Unicode enabled rxvt-clone terminal emulator (urxvt)'
  depends=(
    'rxvt-unicode-terminfo'
    'libxft'
    'perl'
    'startup-notification'
    'libnsl'
    'libptytty'
    'libxext'
    'libxmu'
  )
  optdepends=('gtk2-perl: to use urxvt-tabbed')

  # install freedesktop menu
  for _f in urxvt urxvtc urxvt-tabbed; do
    install -Dm 644 ${_f}.desktop "${pkgdir}/usr/share/applications/${_f}.desktop"
  done

  cd ${pkgname}-${pkgver}
  # workaround terminfo installation
  export TERMINFO="${srcdir}/terminfo"
  install -d "${TERMINFO}"
  make DESTDIR="${pkgdir}" install
  # install the tabbing wrapper ( requires gtk2-perl! )
  sed -i 's/\"rxvt\"/"urxvt"/' doc/rxvt-tabbed
  install -Dm 755 doc/rxvt-tabbed "${pkgdir}/usr/bin/urxvt-tabbed"
}

package_rxvt-unicode-terminfo() {
  pkgdesc='Terminfo files for urxvt'
  conflict=('rxvt-unicode<=9.18-6')
  install -dm 755 "${pkgdir}/usr/share/"
  mv terminfo "${pkgdir}/usr/share/"
}

# vim: ts=2 sw=2 et:
