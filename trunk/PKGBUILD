# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=5.4.0
pkgrel=1
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
sha512sums=('45938ba99fc2cbae49dd72663f143425350629bc30ccf5532d3d6f84a87b6381e6fc559325bf7a1c01147963dd0b3db13ac233255af274ecc17866812859a9d0')
b2sums=('f8c175555517018121e81fbf8e2a4d573799e61575aa32da3f7d7945f499f2119dd712773a467e6962f5e33b93849f9a82beaabc6b9bcb658547ad6f5c6030cb')

prepare() {
  cd ${pkgname}-${pkgver}

  # Rename 'Files' app name to avoid having the same as nautilus
  sed -i '/^\[Desktop Entry/,/^\[Desktop Action/ s/^Name\(.*\)=.*/Name\1=Nemo/' data/nemo.desktop.in
}

build() {
  mkdir -p ${pkgname}-${pkgver}/build
  cd ${pkgname}-${pkgver}/build

  meson --prefix=/usr \
        --libexecdir=lib/${pkgname} \
        --buildtype=plain \
        ..
  samu
}

package() {
  cd ${pkgname}-${pkgver}/build

  DESTDIR="${pkgdir}" samu install
}
