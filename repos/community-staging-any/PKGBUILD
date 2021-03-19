# Maintainer: Maxime Gauduin <alucryd@gmail.com>
# Contributor: Hyacinthe Cartiaux <hyacinthe.cartiaux@free.fr>
# Contributor: Hilton Medeiros <medeiros.hilton@gmail.com>

pkgname=ruby-term-ansicolor
pkgver=1.7.1
pkgrel=2
pkgdesc='A ruby library that colors strings using ANSI escape sequences'
arch=('any')
url='https://rubygems.org/gems/term-ansicolor'
license=('GPL2')
depends=('ruby-tins')
options=('!emptydirs')
source=("https://rubygems.org/downloads/${pkgname#*-}-${pkgver}.gem")
noextract=("${pkgname#*-}-${pkgver}.gem")
sha256sums=('92339ffec77c4bddc786a29385c91601dd52fc68feda23609bba0491229b05f7')

package() {
  local _gemdir="$(ruby -e'puts Gem.default_dir')"

  gem install --ignore-dependencies --no-user-install -N -i "${pkgdir}"/${_gemdir} -n "${pkgdir}"/usr/bin ${pkgname#*-}-${pkgver}.gem
  find "${pkgdir}" -type f -name *.gem -delete

  install -dm 755 "${pkgdir}"/usr/share/licenses/${pkgname}
  ln -s ${_gemdir}/gems/${pkgname#*-}-${pkgver}/COPYING "${pkgdir}"/usr/share/licenses/${pkgname}/
}

# vim: ts=2 sw=2 et:
