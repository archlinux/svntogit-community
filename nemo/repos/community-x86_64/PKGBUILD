# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Alexandre Filgueira <alexfilgueira@cinnarch.com>
# Contributor: Ner0

pkgname=nemo
pkgver=5.4.1
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
sha512sums=('95bc6beb2b5a6eacc5f7914e367644d4b93c4c8f63dac86395aa25838123189b24f930a602e255812d218ab40f654e0c6471a9ff96a432f3eb6fa1418f34bc69')
b2sums=('7fe2485d19eae983aacf04a0b052e2f4edc8a295e7cd3fdc14c8b31e2185dda9ba3cab551efac5711de6d203f0160c4139584a1e916bbd0ebe0094df13c27dc6')

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
