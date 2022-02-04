# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Orhun Parmaksız <orhun@archlinux.org>

pkgname=gsmartcontrol
pkgver=1.1.4
pkgrel=1
pkgdesc="A graphical user interface for the smartctl hard disk drive health inspection tool."
arch=('x86_64')
url="https://gsmartcontrol.sourceforge.io/home/"
license=('GPL')
depends=('smartmontools' 'gtkmm3' 'xorg-xmessage' 'hicolor-icon-theme')
optdepends=('polkit: to run gsmartcontrol directly from menu'
            'xterm: to update the drive database')
source=("https://github.com/ashaduri/gsmartcontrol/releases/download/v${pkgver}/gsmartcontrol-${pkgver}.tar.bz2"
        org.archlinux.pkexec.gsmartcontrol.policy
        gsmartcontrol_polkit)
sha256sums=('fc409f2b8a84cc40bb103d6c82401b9d4c0182d5a3b223c93959c7ad66191847'
            '98ae73cbe39be31f885d8c4d09cbfac7b454534ea1ba7cb5a8d23365dc22212a'
            '66f952196db24d6e3ee454b03481d52e0281c3bbf8be180600bf5ba7b39ec0ea')

prepare() {
	cd ${pkgname}-${pkgver}

        # Modify desktop file
        sed -i "s|^Exec=.*|Exec="@prefix@/bin/gsmartcontrol_polkit"|" \
                data/gsmartcontrol.desktop.in
}

build() {
	cd ${pkgname}-${pkgver}
	CXXFLAGS+=' -std=c++11' ./configure --prefix=/usr --sbindir=/usr/bin/
	make
}

check() {
	cd ${pkgname}-${pkgver}
        make check
}

package() {
	cd ${pkgname}-${pkgver}

	make DESTDIR="${pkgdir}" install

        # Install launcher script
        install -m755 "${srcdir}"/gsmartcontrol_polkit \
                "${pkgdir}/usr/bin/gsmartcontrol_polkit"

        # Install policy file
        install -Dm644 "${srcdir}"/org.archlinux.pkexec.gsmartcontrol.policy \
                "${pkgdir}/usr/share/polkit-1/actions/org.archlinux.pkexec.gsmartcontrol.policy"
}
