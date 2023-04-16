# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=5.6.5
pkgrel=2
pkgdesc="Cinnamon file manager (Nautilus fork)"
arch=(x86_64)
url="https://github.com/linuxmint/${pkgname}"
license=(GPL)
depends=(cinnamon-desktop dconf gvfs exempi libexif libnotify libxml2
         python xapp)
optdepends=('cinnamon-translations: i18n'
            'ffmpegthumbnailer: support for video thumbnails'
            'catdoc: search helpers support for legacy MS Office files'
            'ghostscript: search helpers support for PostScript files'
            'libgsf: search helpers support for MS Office files'
            'libreoffice: search helpers support for legacy MS Office powerpoint files'
            'odt2txt: search helpers support for LibreOffice files'
            'poppler: search helpers support for PDF')
makedepends=(meson samurai gobject-introspection intltool libgsf)
source=(${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('b37181e419d5a9427931d29f2addf9faebca7d74d8b8337dc9cb62ebc3b8f8d9dcef978bc6fc9be65efc41bd2a153685849f10cac9e28ffb3ccb3a8dee5aa739')
b2sums=('1ead71e79170e977e21dd631f7875198b3aa411689bd59b9c64b50a3c3b02a396f2b1cbc1e1420bf242004a6a724b8498e7e0cdd2b48b9d5e54ed97d21331cba')

prepare() {
  cd ${pkgname}-${pkgver}
  # Rename 'Files' app name to avoid having the same as nautilus
  sed -i '/^\[Desktop Entry/,/^\[Desktop Action/ s/^Name\(.*\)=.*/Name\1=Nemo/' data/nemo.desktop.in
}

build() {
  arch-meson --libexecdir=lib/${pkgname} ${pkgname}-${pkgver} build
  samu -C build
}

package() {
  DESTDIR="${pkgdir}" samu -C build install
}
